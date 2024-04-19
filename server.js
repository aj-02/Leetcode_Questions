const express = require('express');
const { Pool } = require('pg');
const bcrypt = require('bcrypt');

const app = express();
const port = 3000;
app.use(express.json());

class Database {
  #userPassword;
  
  constructor() {
    this.pool = new Pool({
      user: 'postgres',
      host: 'localhost',
      database: 'haqdarshak',
      password: 'S@ntacruz1',
      port: 5432,
    });
  }

  set userPassword(password) {
    this.#userPassword = password;
  }

  async storePassword(username) {
    if (!this.#userPassword) {
      throw new Error('Password not provided');
    }

    const hashedPassword = await bcrypt.hash(this.#userPassword, 10);
    const client = await this.pool.connect();
    try {
      
      const queryText = 'INSERT INTO sample (username, password) VALUES ($1, $2)';
      const result = await client.query(queryText, [username, hashedPassword]);
     
      return true;
    } catch (error) {
      console.error('Error storing password:', error);
      return false;
    } 
  }
  
  async checkPassword(username, password) {
    const client = await this.pool.connect();
    try {
      const queryText = 'SELECT password FROM sample WHERE username = $1';
      const result = await client.query(queryText, [username]);
      if (result.rows.length === 0) {
        return false; 
      }
      const hashedPassword = result.rows[0].password;
      return await bcrypt.compare(password, hashedPassword);
    }  catch (error) {
        console.error('Error storing password:', error);
        return false;
      } 
  }
}

const db = new Database();

app.post('/check-password', async (req, res) => {
  const { username, password } = req.body;
  
  if (!username || !password) {
    return res.status(400).json({ error: 'Username and password are required' });
  }
  
  try {
    const passwordMatch = await db.checkPassword(username, password);
    if (passwordMatch) {
      res.json({ message: 'Password is correct' });
    } else {
      res.status(401).json({ error: 'Password is incorrect' });
    }
  } catch (error) {
    console.error('Error checking password:', error);
    res.status(500).json({ error: 'Internal server error' });
  }
});

app.post('/store-password', async (req, res) => {
  const { username, password } = req.body;
  if (!username || !password) {
    return res.status(400).json({ error: 'Username and password are required' });
  }

  db.userPassword = password;

  try {
    const success = await db.storePassword(username);
    if (success) {
      res.json({ message: 'Password stored successfully' });
    } else {
      res.status(500).json({ error: 'Failed to store password' });
    }
  } catch (error) {
    console.error('Error storing password:', error);
    res.status(500).json({ error: 'Internal server error' });
  }
});

app.listen(port, () => {
  console.log(`Server is listening at http://localhost:${port}`);
});

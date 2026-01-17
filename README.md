# C++ User Database (WIP)

This is a small C++ console program I’m working on to learn how user login systems and data persistence work without using any external libraries or databases.

Users can sign up, log in, and view stored profile information. All data is saved to a text file so it persists between runs.

---

## Current functionality

- Create a new user with:
  - ID
  - Name
  - Age
  - Username
  - Password
- Save user data to `userstorage.txt`
- Log in as a returning user
- Check username and password against stored data
- Load user data after login
- Basic menu after login:
  - View profile (works)
  - Update profile (not implemented yet)
  - Delete profile (not implemented yet)
  - Exit

---

## Data storage format

Each user is stored on a single line in `userstorage.txt`:


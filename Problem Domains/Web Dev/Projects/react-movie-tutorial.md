# React Movie Tutorial


https://www.youtube.com/watch?v=G6D9cBaLViA


## Setup

setup [Node](../FullStack+Backend/Node/Concepts/Setup.md)

Install VS Code

initialize the vite template
```bash
cd ~/react-movie-tutorial/
npm create vite@latest

> npx
> create-vite

│
◇  Project name:
│  react-movie-tutorial
│
◇  Select a framework:
│  React
│
◇  Select a variant:
│  JavaScript
│
◇  Scaffolding project in /mnt/d/git/practice-projects/complete-developer-practice/sample-react/react-movie-tutorial...
│
└  Done. Now run:

  cd react-movie-tutorial
  npm install
  npm run dev
```

and then follow the directions at the tail of the output to initialize the project folder

```bash
cd react-movie-tutorial
npm install
npm run dev
```

this will install all the packages required for our project

for an overview of how npm manages packages see [here](../FullStack+Backend/Node/Concepts/npm.md)

and use a web browser to connect to the URL specified by `npm run dev` to ensure everything was installed and initialized correctly

to enable hot reload in vite, alter the `vite.config.js` file

```js
import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'

// https://vite.dev/config/
export default defineConfig({
  plugins: [react()],
  server: {
    watch: {
      usePolling: true
    }
  }
})
```


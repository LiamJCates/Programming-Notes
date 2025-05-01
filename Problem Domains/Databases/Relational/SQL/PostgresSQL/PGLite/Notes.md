PGlite can be used in both Node/Bun/Deno or the browser, and with any JavaScript framework.

Install and start in Node/Bun/Deno

Install into your project:
```bash
npm install @electric-sql/pglite
```

or using a CDN such as JSDeliver:

```js
import { PGlite } from 'https://cdn.jsdelivr.net/npm/@electric-sql/pglite/dist/index.js'
```

To use the in-memory Postgres:

```js
import { PGlite } from '@electric-sql/pglite'

const db = new PGlite()
```
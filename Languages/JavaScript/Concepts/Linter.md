# ESLint

For general information on linters [here](../../../Methodology/Clean%20Code/Linters.md)

[ESLint](https://en.wikipedia.org/wiki/ESLint) is a popular linter for JavaScript that helps developers identify and fix problems in their code. It allows customization of rules and can automatically fix certain issues.  

**Installation and Usage:**

```bash
npm install eslint --save-dev
npx eslint yourfile.js
```

**Sample Configuration (`.eslintrc.json`):**

```json
{
  "env": {
    "browser": true,
    "es2021": true
  },
  "extends": "eslint:recommended",
  "rules": {
    "semi": ["error", "always"],
    "quotes": ["error", "single"]
  }
}
```


This configuration enforces the use of semicolons and single quotes in JavaScript files.
# npm

NPM stands for Node Package Manager. It is the default package manager for the Node.js runtime environment. 

NPM plays a crucial role in managing packages and dependencies for Node.js projects. It provides a vast online repository of open-source packages and libraries that developers can easily install, update, and uninstall with a single command. This streamlines the process of incorporating third-party code into projects, saving time and effort.

With NPM, developers can share and reuse code efficiently, manage dependencies and their versions across different projects, and ensure that all required packages are installed and compatible, reducing conflicts and issues that can arise from manually managing dependencies.

NPM simplifies the distribution and discovery of packages, making it easier for developers to find and use existing solutions rather than reinventing the wheel. This promotes code reusability, collaboration, and the sharing of best practices within the Node.js community.


You can find modules for every task via the online registry at https:// www.npmjs.com.

Verify that npm is available on your local machine by running the following on the command line:

```bash
$ npm -v
```

If there is no listed version or if the version is lower than the current release, install the latest Node.js LTS version, including npm, by following the directions [here](./npm.md)


Be aware that there is no vetting process or quality control on https:// www .npmjs.com. Anyone can publish packages, and the site relies on the
community to report any that are malicious or broken.

Running the following shows a list of available commands:

```bash
$ npm
```

---

## The package.json File

The package.json file is a key element of each Node.js-based project. While the node_modules folder contains actual code, the package.json file holds all the metadata about the project. Found in the project’s root, it must contain the project’s name and version; in addition, it can contain optional data, such as the project’s description, a license, scripts, and many more details.

The package.json file includes all the information others will need to install required modules on their machine and run the application. As a result, you never have to ship or store the node_modules folder in your code repository, which minimizes the repository’s size. 

The package json file for the Express.js server project in Exercise 1

```JSON
{
    "name": "sample-express",
    "version": "1.0.0",
    "description": "sample express server",
    "main": "index.js",
    "scripts": {
        "test": "echo \"Error: no test specified\" && exit 1",
        "run": "node index.js"
    },
    "author": "",
    "license": "ISC",
    "dependencies": {
        "express":"^4.18.2"
    }
}
```

### Required Fields

The package.json file must contain a name field and a version field. All
other fields are optional. The name field contains the package’s name,
which must be one lowercase word but can contain hyphens and
underscores.

#### Versioning

The version field must follow semantic versioning guidelines, which sug-
gest this format: major.minor.patch; for example, 1.2.3. We call this semantic
versioning because each number conveys a meaning. A major version intro-
duces an incompatible API change. You should generally be very careful
about switching to another major version, as you won’t be able to expect
that your application will work flawlessly. A minor version change adds new
functionality in a backward- compatible manner and therefore shouldn’t
pose problems for your application. A patch version applies backward-
compatible bug fixes, and you should always keep it up to date.

### Dependencies

The most important optional fields specify the dependencies and develop-
ment dependencies. The dependencies field lists all the dependencies needed
to run the project, along with their required version ranges, following the
semantic versioning syntax. By default, npm requires only the major version
and keeps the minor and patch ranges flexible. This way, npm can always
initialize your project with the latest compatible version.
These dependencies are part of your bundled application. When you
install a project on a new machine, all dependencies listed in the package
.json file will be installed and placed in the node_modules folder, next to
package.json.
Your application could require all sorts of dependencies, such as frame-
works and helper modules. 

### Development Dependencies

The devDependencies field lists all the dependencies necessary to develop the
project, along with their versions. Again, only the major version is fixed.
These are required only to develop, and not to run, the application. Hence,
they are ignored by the packaging scripts and are not part of the deployed
application. When you install a project on a new machine, all the develop-
ment dependencies listed in the package.json file will be installed and placed
in the node_modules folder next to package.json.

### package-lock.json File

The npm package manager automatically generates the package-lock.json
file for each project. This lock file resolves a problem introduced by the
use of semantic versioning for dependencies. As mentioned earlier, the
npm default is to define only the major version and to use the latest minor
and patch versions available. While this ensures that your application
includes the latest bug fixes, it introduces a new issue: without an exact ver-
sion, builds aren’t reproducible. Because there’s no quality control in the
npm registry, even a patch or minor version update could introduce an
incompatible API change that should have been a major version change.
Consequently, a slight deviation between versions could result in a broken
build.
The package-lock.json file solves this by tracking the exact version of
every package and its dependencies. 

The package-lock.json file for Exercise 1

```json
{
    "name": "sample-express",
    "lockfileVersion": 2,
    "requires": true,
    "packages": {
        "": {
            "dependencies": {
                "express": "^4.18.2"
            }
        },
        "node_modules/accepts": {
            "version": "1.3.8",
            "resolved": "https:// registry . npmjs . org / accepts /-/ accepts - 1 . 3 . 8 . tgz",
            "integrity": "sha512-PYAthTa2m2VKxuvSD3DPC/Gy+U+sOA1LAuT8mkmRuvw+NACSaeXEhosdQ==",
            --snip--
        },
        --snip--
        "node_modules/express": {
            "version": "4.18.2",
            "resolved": "https:// registry . npmjs . org / express /-/ express - 4 . 18 . 2 . tgz",
            "integrity": "sha512-5/PsL6iGPdfQ/lKM1UuielYgv3BUoJfz1aUwU9vHZ+J7gyvwdQXFEBIEI==",
            "dependencies": {
                "accepts": "~1.3.8",
                --snip--
                "vary": "~1.1.2"
            },
            "engines": {
                "node": ">= 0.10.0"
            }
        },
        --snip--
        "vary": {
            "version": "1.1.2",
            "resolved": "https:// registry . npmjs . org / vary /-/ vary - 1 . 1 . 2 . tgz",
            "integrity": "sha512-BNGbWLfd0eUPabhkXUVm0j8uuvREyTh5ovRa/dyow/BqAbZJyC+bfhskkh=="
        }
    }
}
```

The lock file contains a reference to the project and lists the informa-
tion from the corresponding package.json file. Then it lists all the project’s
dependencies; for us, the only dependency is Express.js, with a pinned version. 

In addition, the file lists all the
dependencies for the Express.js version in use, in this case the accept and
vary packages. The stored artifact’s SHA hash enables npm to verify the
integrity of the resource after downloading it.
Now, with all modules version-locked, every npm install command
will create an exact clone of the original setup. Like package.json, the
package-lock.json file is part of the code repository.

---

## Creating a Project

### Initializing a New Module or Project

To start a new project, run `npm init`, which initializes a new module. This should trigger an interactive guide through which you’ll populate the project’s package.json file:

```bash
$ mkdir sample-express
$ cd sample-express
$ npm init
This utility will walk you through creating a package.json file.
It only covers the most common items, and tries to guess sensible defaults.
--snip--
Is this OK? (yes)
```

At the beginning of each project, you need to initialize a new Node.js setup in an empty folder (created here with mkdir sample-express) using `npm init`. 

For simplicity, keep the default suggestions here. The assistant creates a basic package.json file in your project folder.

---

### Installing the Dependencies

Running `npm install <package>` downloads and places a specific package in the `node_modules` folder, next to your package.json file, and adds it to the
dependencies list in package.json. 


Say you want to create a new Express.js-based server. You’ll need to
install the Express.js package from https://npmjs.com. Here we install a particular version, but to install the latest version, omit the version number and
use npm install express instead:

```bash
$ npm install express@4.18.2
added 57 packages, and audited 58 packages in 1s
found 0 vulnerabilities
```
Now the node_modules folder contains an express folder and additional folders with its dependencies. 

Also, Express.js is listed as a dependency in package.json

```json
{
    "name": " sample-express",
    "version": "1.0.0",
    "description": "",
    "main": "index.js",
    "scripts": {
        "test": "echo \"Error: no test specified\" && exit 1"
    },
    "author": "",
    "license": "ISC",
    "dependencies": {
        "express": "^4.18.2"
    }
}
```

We’ve successfully added Express.js as a dependency.

### Installing the Development Dependencies

Now let’s say you want to use a package called karma for end-to-end testing of the server.

Instead of being a dependency like Express.js, this package is used only during development and is not necessary for running the actual application.

run `npm install --save-dev <package>` to download this package and add it to the devDependencies list in the local package.json file:

```bash
$ npm install --save-dev karma@5.0.0
added 128 packages, and audited 186 packages in 3m
9 vulnerabilities (1 moderate, 4 high, 4 critical)
```
To address issues that do not require attention, run:

```bash
npm audit fix
To address all issues (including breaking changes), run:
npm audit fix --force
Run `npm audit` for details.
```

Notice that, after installing the karma package, npm indicates that this version has known vulnerabilities. Nonetheless, it is added to the node_modules folder and listed as a devDependency in package.json. We will follow the suggestions to fix the issues in a bit.

### Auditing the package.json File

During installation, npm indicated that karma has a vulnerability, so let’s verify this. 

The npm audit command inspects the local package.json file for any known vulnerabilities:

```bash
$ npm audit
# npm audit report
--snip--
karma <=6.3.15
Severity: high
Open redirect in karma - https://github.com/advisories/GHSA-rc3x-jf5g-xvc5
Cross-site Scripting in karma - https://github.com/advisories/GHSA-7x7c-qm48-pq9c
Depends on vulnerable versions of log4js
Depends on vulnerable versions of ua-parser-js
fix available via `npm audit fix --force`
Will install karma@6.4.1, which is a breaking change
--snip--
9 vulnerabilities (1 moderate, 4 high, 4 critical)
To address issues that do not require attention, run:
npm audit fix
```

To address all issues (including breaking changes), run:

```bash
npm audit fix --force
```

Running the command returns a detailed report about the version and severity of each problematic package, as well as a summary of all the issues
found in the currently installed Node.js modules.

The npm package manager also indicated that the issues could be fixed automatically with npm audit fix. Alas, it warns us about breaking changes in
the latest karma version. To accommodate those, we need to use the `--force` flag. 

Use npm audit every few months, along with npm update, to avoid using outdated dependencies and creating security risks:

```bash
$ npm audit fix --force
added 13 packages, removed 41 packages, changed 27 packages, and audited 158 packages in 5s
```

Now we see that the devDependencies list in package.json has the latest karma version, and another run of npm audit reports that there are no more known vulnerabilities in the installed packages.

### Cleaning Up the node_modules Folder

Running npm prune inspects the local package.json file, compares it to the local node_modules folder, and removes all unnecessary packages. You should use
it during development, after adding and removing packages, or when performing general cleanup chores.

Let’s check that the audit we just performed didn’t install any unnecessary packages:

```bash
$ npm prune
up to date, audited 136 packages in 1s
found 0 vulnerabilities
```

The output looks fine; there are no issues with our packages.

### Updating All Packages

Running npm update updates all installed packages to their latest acceptable version. You should use this command frequently to avoid outdated dependencies and security risks:

```bash
$ npm update
added 1 package, removed 1 package, changed 1 package, and audited 158 packages in 8s
found 0 vulnerabilities
```

As you can see, npm update displays a summary of the updates.

### Removing a Dependency

Running npm uninstall package removes the package and its dependencies from the local node_modules folder and package.json file. You should use this command to delete modules you don’t need anymore. Say you decide that end-to-end tests with karma are no longer necessary:

```bash
$ npm uninstall karma
removed 71 packages, and audited 138 packages in 3s
found 0 vulnerabilities
```

The command’s output shows the changes made to the node_modules folder. The package was removed from package.json as well.

### Installing a Dependency

Running `npm install` downloads all dependencies and devDependencies from the npm repository and places them in the node_modules folder.

Use this command to install an existing project on a new machine.

For example, to install a copy of the Express.js project in a new folder, you could create a new empty folder and copy only the package.json and package-lock.json files into it. Then you could run the npm install command inside this folder:

```bash
$ npm install
added 137 packages, and audited 138 packages in 3s
found 0 vulnerabilities
```

Whenever you clone the repository or create a new project from a package.json file, run npm install. As with all previous commands, npm shows
a status report listing any vulnerabilities.

### Using npx to Execute a Script Only Once

When you installed Node.js, you also installed npx, which stands for node package execute. This tool enables you to execute any package from the registry
without installing it beforehand. 

This is useful when you need to run some code only once. For example, you might use a scaffolding script that initializes a project but is neither a dependency nor a development dependency.

The npx tool works by checking whether the executable you’re trying to run is available through the `$PATH` environment variable or local project binaries. If this is not the case, npx installs the package to a central cache instead of your local node_modules folder. 

Say you want to check your package JSON for syntax errors. For this, you can use the jsonlint package. As this package is neither required to run the project nor part of your development process, you don’t want to install it into your node_modules folder:

```bash
$ npx jsonlint package.json
Need to install the following packages:
jsonlint
Ok to proceed? (y) y
{
    "name": " sample-express",
    "version": "1.0.0",
    "description": "",
    "main": "index.js",
    "scripts": {
        "test": "echo \"Error: no test specified\" && exit 1"
    },
    "author": "",
    "license": "ISC",
    "dependencies": {
        "express": "^4.18.2"
    }
}
```

This calls jsonlint to validate our package.json file via npx. First npx installs the package into the global cache folder, then runs jsonlint. It prints
the content of our package.json file and reports no errors. Check your node_modules folder; jsonlint shouldn’t be installed. Nonetheless, on each subsequent call of npx, you’ll find jsonlint available.


npm

npm (no capitals!) is a package manager - a gigantic repository of plugins, libraries, and other tools, which provides us with a command-line tool we can use to install these tools (that we call “packages”) in our applications. We will then have all our installed packages’ code locally, which we can import into our own files.

 Funnily enough, npm does [not](https://www.npmjs.com/package/npm#is-npm-an-acronym-for-node-package-manager) stand for “Node Package Manager”, though you will often see it referred to as such.



### package.json

npm revolves around a file called package.json. It’s a JSON file containing information about our project, such as its name or any dependencies and their version numbers. npm can read this file and do things such as install all of the listed dependencies with the correct versions, and running commands that you’ve set as an npm script


https://www.theodinproject.com/lessons/node-path-javascript-npm

Here is the package.json file for The Odin Project’s curriculum repo that houses all of the lesson files (including this lesson you are doing right now):
```json
{
  "name": "curriculum",
  "version": "1.0.0",
  "description": "[The Odin Project](https://www.theodinproject.com/) (TOP) is an open-source curriculum for learning full-stack web development. Our curriculum is divided into distinct courses, each covering the subject language in depth. Each course contains a listing of lessons interspersed with multiple projects. These projects give users the opportunity to practice what they are learning, thereby reinforcing and solidifying the theoretical knowledge learned in the lessons. Completed projects may then be included in the user's portfolio.",
  "scripts": {
    "lint:lesson": "markdownlint-cli2 --config lesson.markdownlint-cli2.jsonc",
    "lint:project": "markdownlint-cli2 --config project.markdownlint-cli2.jsonc",
    "fix:lesson": "markdownlint-cli2 --fix --config lesson.markdownlint-cli2.jsonc",
    "fix:project": "markdownlint-cli2 --fix --config project.markdownlint-cli2.jsonc"
  },
  "license": "CC BY-NC-SA 4.0",
  "devDependencies": {
    "markdownlint-cli2": "^0.12.1"
  }
}
```

There’s a lot of stuff here and we don’t need to understand it all yet. The point is that if you were to clone the curriculum repo, if you ran npm install, npm would read this package.json file and see that it needs to install the markdownlint-cli2 package. Once this package is installed, you’ll be able to run any of the four npm scripts that use that package. The curriculum repo itself does not actually contain the code for the markdownlint-cli2 package, as anyone cloning the repo can just run npm install to let npm grab the code for them.


TODO
https://docs.npmjs.com/downloading-and-installing-packages-locally
https://docs.npmjs.com/creating-a-package-json-file
https://peterxjang.com/blog/modern-javascript-explained-for-dinosaurs.html

Any packages we install are called “dependencies”, but if any packages are only used during the development process and their code is not needed for the user-facing app (such as the Jest testing framework), we call them development dependencies.
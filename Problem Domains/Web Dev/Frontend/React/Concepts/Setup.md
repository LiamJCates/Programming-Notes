# Setup


### How to Start

There are multiple ways to start using React in your projects, from attaching a set of `<script>` tags which serve React from a CDN, to robust toolchains and frameworks that are highly configurable and allow for increased scalability and optimization.

Some examples of these toolchains include:

Vite’s React Config
Gatsby
NextJS
Create React App (Deprecated)

NOTE: 
Create React App, or CRA, was the official way to scaffold new React projects since its introduction in 2016. Unfortunately, owing to many reasons, CRA was deprecated in early 2023. Due to CRA’s popularity, you’ll see it mentioned in many tutorials and guides. However, it’s no longer recommended to use it for new projects.


Why do we need these toolchains? Can’t we just make our own as we see fit?

Yes, but it’s hard. React is a complex beast and there are many moving parts. Before you can start writing any sort of code that provides functionality, you would need to configure at least the following:

Package Management ([NPM](https://www.npmjs.com/), Yarn)  
Module bundling ( [Webpack](https://webpack.js.org/) , [Parcel](https://parceljs.org/))  
Compilation ( [Babel](https://babeljs.io/) )   
React itself    

All of this, and sometimes much more, is required to get a React project and development environment up and running.


### Simplifying the process

you can breathe a sigh of relief to learn that we can get started with a single terminal command.

Vite builds frontend tools for developers and it leverages the latest technologies under the hood to provide a great developer experience. Fortunately, it also caters to the React ecosystem. We will use Vite’s CLI to quickly create a template React project. It requires minimal configuration and provides extremely useful tools right out of the box, allowing us to get straight to the learning.








## Install WSL

https://learn.microsoft.com/en-us/windows/wsl/install

### Step 1: Installations

#### Step 1.1: Installing WSL2

Open PowerShell in administrator mode by searching for it in your applications, right clicking the top option, and then selecting run as administrator. You might get a prompt asking if you want to allow Windows Powershell to make changes to your device: click yes.

Enter the following command
```shell
wsl --install
```
After a few minutes you’ll be prompted to reboot your computer; do so.
You should see an open Powershell window, prompting you to enter a username and a password. Your username should be lowercase, but can otherwise be whatever suits you. You’ll also need to enter a new password.
When entering your password you might notice that you aren’t seeing any visual feedback. This is a standard security feature in Linux, and will also happen in all future cases where you need to enter a password. Just type your password and hit Enter.

#### Step 1.2.1: Install Windows Terminal (Windows 10 only)

Windows Terminal is a terminal application that lets you more easily customize and run terminals, as well as supporting multiple tabs which can each run their own different terminals.

Install [Windows Terminal](https://learn.microsoft.com/en-us/windows/terminal/install) by using the direct install option.

#### Step 1.2.2: Setting WSL2 as default (Optional)

Unless you are regularly using other terminals on your computer we recommend that you set WSL2 as the default terminal program when you open Windows Terminal.

Open Windows Terminal by searching for terminal in your applications.
Click the dropdown next to the new tab button (at the top of the windows), and select Settings.
You should see a Default Profile option with a dropdown next to it.
In the dropdown select **Ubuntu**.
Click save at the bottom of the page.

### Step 2 Opening WSL2

On Windows there are three primary ways to open WSL2.

If you set Windows Terminal to open a Ubuntu terminal by default you can start a new WSL2 session by opening the terminal app.
Otherwise you can open Windows Terminal, click the dropdown next to the new tab button (at the top of the windows), and select Ubuntu.
If you search for Ubuntu in the application search bar you should see a application titled Ubuntu; open it to start a new terminal session.

You might notice when you open WSL2 via Windows Terminal, you’ll see a window with a different color scheme and a different icon compared to opening a terminal through Ubuntu in your applications. This is because Windows Terminal comes with a default color scheme for Ubuntu meant to emulate how a real Ubuntu terminal looks. This difference is purely cosmetic, and there is no practical difference between the two.

When opening your WSL2 terminal ensure that you do not see /mnt/c at the start of the line. /mnt/c is where your Windows installation lives when working within WSL2, and messing around there can have unintended consequences.


## Install Node for WSL
https://learn.microsoft.com/en-us/windows/dev-environment/javascript/nodejs-on-wsl


## Install VSCode

Follow the instructions for Visual Studio Code on Windows to install [VSCode](https://code.visualstudio.com/docs/setup/windows).

Step 2: Delete the installer file

Open File Explorer.
Go to the Downloads folder.
Drag VSCodeUserSetup-{version}.exe to the trash.

Step 3: Install WSL Extension

Open Visual Studio Code.
Navigate to the extensions tab.
Find and install the [WSL extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl)

Step 4: Ensure that WSL2 can correctly open VSCode

Open a new WSL2 terminal.

Run the following command to open a new VSCode window.
```bash
code
```
After a few moments a new VSCode window should open, and VSCode should provide a notification that its opening in WSL2.







### Creating a React app

First follow [Setup](./GettingStarted/Setup.md)  
  
Please make sure that you are using the latest LTS version of Node, otherwise errors may occur. Open up the terminal and the folder containing your projects. Then enter the following command (you can replace my-first-react-app with any name you want):
```bash
npm create vite@latest my-first-react-app -- --template react
```
If you see the following output, enter y and then press enter:
```bash
Need to install the following packages:
  create-vite@5.X.X
Ok to proceed? (y)
```
Once the command has executed, it should output the next steps for you to follow:
```bash
cd my-first-react-app
npm install
npm run dev
```
Provided everything has gone according to plan, head over to **localhost:5173**
Using nvm (Node.js Version Manager) makes it easier to install and manage multiple versions of Node.js on a single local environment. Even if you only need a single version of Node.js right now, we still recommend using nvm because it allows you to switch between different versions of Node (depending on the requirements of your project) with minimal hassle.

## nvm

nvm is a version manager for node.js, designed to be installed per-user, and invoked per-shell. nvm works on any POSIX-compliant shell (sh, dash, ksh, zsh, bash), in particular on these platforms: unix, macOS, and windows WSL.



https://github.com/nvm-sh/nvm


### Download the install script

Using curl, or wget, download the installation script. In the URL below make sure you replace v0.35.0 with the latest version of nvm.

```bash
curl -sL https://raw.githubusercontent.com/nvm-sh/nvm/v0.35.0/install.sh -o install_nvm.sh
```
It's not a bad idea to open the install script and inspect its contents given that you just downloaded it from the Internet.

### Run the install script

Run the install script with bash.
```bash
bash install_nvm.sh
```
This script clones the nvm repository into ~/.nvm. Then it updates your profile (~/.bash_profile, ~/.zshrc, ~/.profile, or ~/.bashrc) to source the nvm.sh it contains.

You can confirm that your profile is updated by looking at the install script's output to determine which file it used. Look for something like the following in that file:
```bash
export NVM_DIR="$HOME/.nvm"
  [ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
  [ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion
```
Restart your terminal

In order to pick up the changes to your profile either close and reopen the terminal, or manually source your respective ~/.profile.

```bash
source ~/.bash_profile
```
Verify it worked

Finally, you can verify that it's installed with the command command:

```bash
command -v nvm
```
Should return nvm. Note: You can't use the which command with nvm since it's a shell function and not an actual application.


### Use nvm to install the latest LTS release of Node.js and npm

Now that you've got nvm installed let's use it to install, and use, the current LTS version of Node.js.

```bash
nvm install --lts
```

        Installing latest LTS version.
        Downloading and installing node v10.16.3...
        Downloading https://nodejs.org/dist/v10.16.3/node-v10.16.3-darwin-x64.tar.xz...
        ######################################################################## 100.0%
        Computing checksum with sha256sum
        Checksums matched!
        Now using node v10.16.3 (npm v6.9.0)
        Creating default alias: default -> lts/* (-> v10.16.3)

Verify it worked, and that the version is correct:

```bash
node --version
# => v10.16.3
which node
# => /Users/joe/.nvm/versions/node/v10.16.3/bin/node
```

Note this line Creating default alias: default -> lts/* (-> v10.16.3). This indicates that nvm has set lts/* as the default alias. Practically this means that anytime you start a new shell, and the nvm.sh script is sourced, it will default that shell to using the installed lts release. You can change this behavior using the nvm alias command.

Example to set the default version of node to use when starting a new shell to 10.0.0:

```bash
nvm alias default 10.0.0
```


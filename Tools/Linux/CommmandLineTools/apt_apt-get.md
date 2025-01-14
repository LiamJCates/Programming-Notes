Like many other Ubuntu users, you may have wondered – What is the difference between apt-get and apt? Or perhaps – When to use apt-get and when apt?

apt-get is a command line program used to interact with the APT (Advanced Package Tool) package management system. However, this is just one of the tools used to communicate with the APT system. Along with apt-get, there are also apt-cache, apt-config, and (the newly added) apt.

### What is the Difference?

There are four main differences between apt and apt-get:

    The apt tool merges functionalities of apt-get and apt-cache
    Additional output and improved design
    Changes in command syntax for existing functionalities
    Two new functionalities exclusive to the apt command


###  APT Combines APT-GET and APT-CACHE Functionalities

Prior to Ubuntu 16.04, users regularly interacted with the APT package manager through the use of command line tools: apt-get, apt-cache, and apt-config. Although these tools offer many functionalities, most average users did not utilize all of the commands they provide.

Therefore, Linux wanted to create a simplified tool that only consisted of essential commands. With the release of Ubuntu 16.04 and Debian 8, they introduced a new command-line interface – apt.

The main goal for this novelty was to merge the most commonly used apt-get and apt-cache commands under the same command prefix.

Note: The apt command is more user-friendly compared to the existing APT tools. Also, it was simpler to use as you didn’t have to switch between apt-get and apt-cache.


### Additional Output and Improved Design

Apart from the apparent differences between commands, apt also introduced changes to the output design.

Along with updating your local repository, the update command now includes an additional line displaying the number of packages that should be upgraded. There is a difference between updating and upgrading packages on your system. Therefore, this novelty serves as a useful reminder to upgrade the required packages.

Once the output displays the number of packages that can be upgraded, you can prompt the package manager to see a list of these packages. Run the apt list --upgradable command, and the output shows the specified list.

The output includes improved design for clearer representation with color emphasis.

Finally, the apt command added a progress bar displaying the upgrade process. This is a simple yet useful addition that gives the user more information about the given process.


### apt vs apt-get Commands

Although apt commands replace commonly used apt-get and apt-cache functions, they are not backward compatible with all of them. You cannot always replace the older package managers with apt.

In the table below, see the apt command for any given function, as well as which command it replaces.
Command Function	Existing Command	apt Command
Update the package repository	apt-get update	apt update
Upgrade packages	apt-get upgrade	apt upgrade
Upgrade packages and remove unnecessary dependencies	apt-get dist-upgrade	apt full-upgrade
Install a package	apt-get install [package_name]	apt install [package_name]
Remove a package	apt-get remove [package_name]	apt-remove [package_name]
Remove a package with configuration	apt-get purge [package_name]	apt purge [package_name]
Remove unnecessary dependencies	apt-get autoremove	apt autoremove
Search for a package	apt-get search [package_name]	apt-get search [package_name]
Show package information	apt-cache show [package_name]	apt show [package_name]
Show active package sources	apt-cache policy	apt policy
Show installed and available versions of a package	apt-cache policy [package_name]	apt policy [package_name]


### New apt Commands

Apart for simplifying existing commands, apt has a couple of its own. They were added to fulfill the needed command functions listed below.
Command Function	New apt Command
List packages by criteria	apt list
Edit sources list	apt edit-sources
When to Use apt Instead of apt-get?

Most Linux users suggest using the apt command instead of apt-get whenever you can. Not only is it easier to type and remember, it performs tasks much faster.

Naturally, there are instances where substituting apt-get or apt-cache isn’t possible. Although you may still need to switch between command-line interfaces, many believe the apt command will eventually take over. For now, there is no official statement when or whether that will happen.

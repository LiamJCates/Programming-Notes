## Customizing Eclipse


### Creating a Perspective
When you customize Eclipse, you're really customizing a perspective.
You can start out by modifying the current perspective, or you can create a new one.
It isn't dangerous to modify the current one, because you can always get back to the original.
use the Window menu, Perspective, then select the Reset Perspective item.

It's nice not to lose all your customizations by having to reset a perspective. So I recommend creating a new perspective
using the Window menu > Perspective > Save Perspective As.
In the preferences section is Perspectives-General we can
set the default that Eclipse will open to
delete unneeded perspectives


### Saving Perspectives
We can save a new arrangement as its own perspective.
use the Window > Perspective > Save Perspective As...

You can hover over the icon, and you'll get the name of the perspective after a short delay.
To delete a perspective go to Preferences at the bottom of the Window menu, open up the general area, and scan down for perspectives, then we can select the perspective we want to delete, click Delete, and finally Apply and Close.

When you double-click a tab, it maximizes to take up the whole screen. Double-click it again, and it goes back to where it was.

For fine-grained control over your perspective there are even more options if you go into the Window menu and select Customized Perspective. We're not going to get into that much detail right now, but you can change what toolbars are showing, the menu visibility, and more, and all of that will save with your perspective as well.


### Toolbars and Menus

create a new perspective for experimenting.
reset perspective doesn't do a complete job when toolbars are modified

We modify the toolbar in Window > Perspective > Customize Perspective

If you go to a separator bar and you hover, you'll get a crosshairs icon. And then you can click and drag to move the toolbar that was just to the right of that separator bar.
If you don't want to have toolbar sections moved around, you can lock it down. Using Quick Access, just type lock, and then select the Toggle Lock Toolbars option.
Now the little separator bars are gone. Also since the toolbar uses the mouse anyway, you can just right-click on the toolbar and select the option to lock or unlock the toolbar depending on its current state.

Finally if you don't want the toolbar at all, you can use the Windows menu, Appearance submenu, and select Hide Toolbar. Sometimes this also disables Quick Access on me, but I've discovered that sometimes it works, and changing other visual elements like opening up a file via the Package Explorer will wake it back up sometimes.

### Shortcuts (Key Bindings)

keyboard shortcuts are customized from the preferences window > General > Keys
Starting at the top, we have Schemes that we can pick. We have just choices for Default and Emacs,

Good Bindings to set include
Open Declaration which jumps right to the declaration of the class or methods.
The References command shows me everywhere a method or class is referenced.

If you ever want to get a single command's original binding back, you can just use the Restore Command button
If you want to wipe out all your hard one customizations in a single click, the Restore Defaults button will do that.
You can export bindings as a CVS file

You can have more than one binding for a command, but you can't just enter a second one in the binding box. What you do is select the command, and click the Copy button. It gives you a copy without a shortcut, and we can assign a second shortcut to this command now.

Eclipse supports key sequences for shortcuts.

To back up bingings, use the File menu, select Export, open the General section, select Preferences. By default, it's going to save all preferences, and that isn't a bad idea, but you can also save just the keys preferences, click Browse. You'll navigate to a folder of your choosing, provide a name for the key prefs export, click Save, and Finish, and you're done. Well, almost. You do want to be able to import them, but it's almost the same process. File, Import this time, General, and Preferences, click Next, navigate to your saved prefs, click the file, click Open. If you saved multiple prefs, you can elect to Import them all, or import a single section. Click Finish, and you'll have them back.


### Uninstall Software
On Windows and Linux, Help > About Eclipse IDE
Under the About, you'll see the installation details section which will give you quite a bit of information by clicking on things. You can also see your Installation History, Features that have installed, Plug-ins, and Configuration information.

This is also where you uninstall things from. If you click on an item, you'll notice the Uninstall button enables. When you uninstall a feature, Eclipse will prompt you to restart, and it's a good idea to do so. We're going to look at some other ways to uninstall, but remember this is here, as it's one of the finest grained ways to uninstall items that Eclipse offers.

### Install Software
On Windows and Linux, Help > Install New Software item.
You'll see "Work with" a site pop-up, and there are quite a few that are from eclipse. org.
A lot of those things that we saw when we were on the website, you can download here now, and you can also get additional tooling. I'll select the All Available Sites option, which is the slowest choice. This presents a long list of packages I can update. The package filter is right below

The more modern way to install features to Eclipse is through the Marketplace item on the Help menu.
You'll see by default, there are three Marketplaces available, and after a few seconds, the featured items will populate. Again we have a convenient search area.
There are other tabs you can explore in the Marketplace, but let's look at the Installed tab.
This is the other way of finding out what's installed. What's nice is if you did use the Marketplace to install something, you can both update and uninstall it from this tab.

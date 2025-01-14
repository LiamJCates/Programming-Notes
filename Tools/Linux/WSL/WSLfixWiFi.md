1) Wipe old installation

	Uninstall any Ubuntu (18.10, 20.04, etc...)

	Go to Device Manager
	check View > Hidden Device

	Uninstall all
	Hyper-V Virtual Extensions
	Hyper-V Virtual Switch Extensions

	Disable "Windows Sub-system for Linux" from Features
	Restart

	Enable "Windows Sub-system for Linux" from Features
	Restart

	Reinstall Ubuntu from the windows store


2) Make sure you don't have compression on the Temp folder

	Open the temp folder: %TEMP%
	(Right Click -> Properties -> Advanced)



3) Fix the resolv.conf

	sudo nano /etc/resolv.conf
	Remove line
		nameserver 17...
	add line
		nameserver 8.8.8.8

	ctrl + o and ctrl + x to write a quit

4) Stop resolv.conf generation

	sudo nano /etc/wsl.conf
	Paste the following in:

	[network]
	generateResolvConf = false

	ctrl + o and ctrl + x to write a quit
	close WSL and reopen


5) Reset/Flush windows DNS

	Open Powershell as administrator

	Run Commands
		wsl --shutdown
		netsh winsock reset
		netsh int ip reset all
		netsh winhttp reset proxy
		ipconfig /flushdns
		netsh winsock reset
		shutdown /r


hopefully the issue is fixed :)

<p align="center">
  <img width="400" height="200" src="https://i.imgur.com/5FxeFsf.png">
</p>
### Visualise loaded modules on a process  

> Make sure to change character set to "not set"  

Very simple, uses EnumProcessModulesEx, prints respective module path and HMODULE. Can be changed easily to only view 32bit / 64bit modules with the EnumProcessModulesEx Filter (i have it set to LIST_MODULES_ALL by default). Figured i would put this on my github since i use it quite a bit for reversal.  

![Example](/images/example.png)

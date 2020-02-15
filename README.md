# cs300-wi20-group5/project

This is a group project for a psu cs300 course. 

### to get code locally: 

```bash
git clone https://github.com/cs300-wi20-group5/project.git
```

### set your git remote:

```bash
git init 
git remote set-url origin https://github.com/cs300-wi20-group5/project.git 
```

### to create your own branch:

```bash
git checkout -b <branch-name> 
```

### to add / commit changes:

```bash
git add *   
```
or
```bash
git add file1 file2 etc...
```
```bash
git commit -m "your commit comment here"
```

### to push to your branch:

```bash
git push origin <branch-name>
```
### How to build on the linux terminal
start by making a directory named build for all the build files
```bash
mkdir build && cd build
```
Then run cmake for the directory above; it will place all of the build files inside the current directory

```bash
cmake ..
```
Once it's done, you can then run make

```bash
make
```
If the build is successful, it will then make an executable named "cs300-wi20" which you can then run  

# janet-whereami

whereami wrapper for janet

## use from source

```
git clone --recurse-submodules https://github.com/Saikyun/janet-whereami
cd janet-whereami
jpm build
```

### try in repl

```
janet
Janet 1.16.1-87f8fe14 linux/x64 - '(doc)' for help
repl:1:> (use ./build/whereami)
@{_ @{:value <cycle 0>} get-executable-path @{:private true} get-module-path @{:private true} :macro-lints @[]}
repl:2:> (get-executable-path)
"/usr/local/bin/janet"
repl:3:> (get-module-path)
"/home/.../where-am-i/build/whereami.so"
repl:4:> 
```

## install
```
[sudo] jpm install https://github.com/saikyun/janet-whereami
```

When using this dependency, I think you need to run `jpm build` too. Will try to figure out how to autobuild.

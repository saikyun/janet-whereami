(declare-project
  :name "janet-whereami"
  :author "saikyun"
  :license "MIT"
  :description "Janet wrapper for whereami -- which lets you get the path to a built binary. Useful for relative paths."
  :url "https://github.com/Saikyun/janet-whereami"
  :repo "git+https://github.com/Saikyun/janet-whereami")

(def o (os/which))

(declare-native
  :name "whereami"

  :cflags ["-Iwhereami/src"]

  :source ["janet_whereami.c"
           "whereami/src/whereami.c"]

  :headers ["whereami/src/whereami.h"])

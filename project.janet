(declare-project
  :name "janet-whereami"
  :author "saikyun")

(def o (os/which))

(declare-native
  :name "whereami"

  :cflags ["-Iwhereami/src"]

  :source ["janet_whereami.c"
              "whereami/src/whereami.c"]

  :headers ["whereami/src/whereami.h"])

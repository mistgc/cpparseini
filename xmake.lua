add_includedirs("include")
target("cpparseini_static")
    set_kind("static")
    add_files("src/*.cc")

target("cpparseini_shared")
    set_kind("shared")
    add_files("src/*.cc")

includes("test")

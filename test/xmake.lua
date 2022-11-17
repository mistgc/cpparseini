local test_cases = {
    "add_section",
    "display",
    "modify_section",
    "read_valid_line",
    "remove_section"
}

for k, v in ipairs(test_cases) do
    target("test_"..v)
        set_kind("binary")
        add_files("test_"..v..".cc")
        add_deps("cpparseini_static")
    target_end()
end

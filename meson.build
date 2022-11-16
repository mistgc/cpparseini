project('cpparseini', 'cpp')

inc = include_directories('include')

src = files('src/cpparseini.cc')

cpparseini = both_libraries('cpparseini', src, include_directories: inc)

cpparseini_dep = declare_dependency(
    include_directories: inc,
    link_with: cpparseini.get_static_lib()
)

subdir('test')

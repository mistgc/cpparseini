test_cases = [
  'read_valid_line',
  'display',
  'remove_section',
  'add_section',
  'modify_section'
]

foreach i : test_cases
  executable(
    'test_' + i,
    'test_' + i + '.cc',
    dependencies: cpparseini_dep
  )
endforeach

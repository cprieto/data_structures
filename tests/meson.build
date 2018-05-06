criterion = dependency('criterion')
src = ['test_linkedlist.c']
all_tests = executable('all_tests', src,
  dependencies: criterion, 
  include_directories: inc, 
  link_with: dslib)

test('all tests', all_tests)

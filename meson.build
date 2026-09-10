project('static-tests', 'c',
	default_options : [ 'warning_level=2' ],
        license: 'Public Domain')

# Common arguments for all tests
common_test_c_args = ['-Dmain=_main_disabled', '-Wno-missing-prototypes']
common_test_link_args = ['-Wl,-zmuldefs']

# Our "real" binary. Just here for illustrative purposes.
executable('example',
           'example.c', 'otherfile.c',
           install: false)

# Test binary with minimal dependencies (uses symbol ignoring for missing symbols)
t = executable('test-example',
               'example.c', 'test-example.c',
               c_args: common_test_c_args,
               link_args: common_test_link_args + ['-Wl,--unresolved-symbols=ignore-all', '-no-pie'],
               install: false)
test('test-example', t)

# Test binary with all dependencies (complete linking, no missing symbol workarounds needed)
t = executable('test-example-full',
               'example.c', 'otherfile.c', 'test-example.c',
               c_args: common_test_c_args,
               link_args: common_test_link_args,
               install: false)
test('test-example-full', t)

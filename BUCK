load('//:buckaroo_macros.bzl', 'buckaroo_deps', 'buckaroo_deps_from_package')
load('//:subdir_glob.bzl', 'subdir_glob')

boost_test = \
  buckaroo_deps_from_package('github.com/buckaroo-pm/boost-test')

prebuilt_cxx_library(
  name = 'linq',
  header_only = True,
  header_namespace = 'linq',
  exported_headers = subdir_glob([
    ('linq', '**/*.h'),
  ]),
  deps = [ x for x in buckaroo_deps() if not x in boost_test ],
  visibility = [
    'PUBLIC',
  ],
)

cxx_test(
  name = 'test',
  srcs = [
    'test.cpp',
  ],
  deps = boost_test + [
    '//:linq',
  ],
)

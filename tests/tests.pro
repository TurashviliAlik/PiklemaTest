TEMPLATE = subdirs

SUBDIRS += auto
CONFIG(release, debug|release): SUBDIRS += benchmarks

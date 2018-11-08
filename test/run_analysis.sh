#../clang --analyze -Xanalyzer -analyzer-checker=alpha.unix.ZChecker -Xanalyzer -analyzer-output=html -o html.dir test.c
#../clang --analyze -Xanalyzer -analyzer-checker=debug.DumpCFG -Xanalyzer -analyzer-output=html -o html.dir2 test.c
#../clang --analyze -Xanalyzer -analyzer-checker=alpha.security.taint.TaintPropagation -Xanalyzer -analyzer-output=html -o html.dir2 test.c
../scan-build --use-analyzer ../clang -analyzer-config stable-report-filename=true -analyzer-config -analyzer-checker=alpha.unix.ZChecker -enable-checker alpha.unix.ZChecker -o scan-build.html.dir make

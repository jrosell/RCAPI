# R's internal C API

## Example: add_one

For creating the RCAPI, you would run this in the RCAPI folder:

```
options(
    usethis.description = list(
        "Title" =  "R Internal C API Usage",
        "Description" = "RCAPI is an example package for R's internal C API usage.",
        "Authors@R" = utils::person(
            "Jordi", "Rosell",
            email = "jroselln@gmail.com",
            role = c("aut", "cre"),
            comment = c(ORCID = "0000-0002-4349-1458")
        ),
        Language =  "en",
        License = "MIT + file LICENSE"
    )
)
usethis::create_package(path = ".")
usethis::use_mit_license()
usethis::use_git()
usethis::use_github()
devtools::document()
usethis::use_package_doc()
usethis::use_c("RCAPI")
```

Once you created the RCAPI_add_one function inside a src/RCAPI.c file and the add_one call from your R/add.R file, you can run:

```
devtools::load_all()
pkgbuild::compile_dll(force = TRUE, register_routines = TRUE)
add_one(1)
```

To document the package and check if all is working well:

```
devtools::check(document = TRUE)
```

## Help with C-level R objects


Install pak::pak("henrikbengtsson/RNativeAPI") to get interactive help about R Native API.

At the C-level, all R objects are stored in a common datatype, the S-expression (SEXP) variant type, with subtypes (SEXPTYPE) for all R's data structures.


### Vectors 

LGLSXP, INTSXP, REALSXP, CPLXSXP, STRSXP, VECSXP, RAWSXP, and EXPRSXP.

### Strings

Character vectors are a more complex object made of vector CHARSXPs.

### Environments

ENVSXP

### Functions

CLOSXPs and the rarer BUILTINSXPs, SPECIALSXPs and FUNSXPs.

### Symbols

SYMSXPs

### Pairlists

Including LISTSXPs and the related NILSXP, LANGSXP, and DOTSXP. This chapter also includes a discussion of attributes, which are powered by pair lists.

### External pointers

XPTRSXPs

## References

https://github.com/hadley/r-internals
https://cran.r-project.org/doc/manuals/R-exts.html
https://cran.r-project.org/doc/manuals/r-release/R-ints.html
https://cran.stat.auckland.ac.nz/doc/manuals/r-devel/R-ints.html
http://adv-r.had.co.nz/C-interface.html
https://deepr.gagolewski.com/index.html
https://blog.davisvaughan.com/posts/2019-03-02-now-you-c-me/

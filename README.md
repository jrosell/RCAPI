# R's internal C API

RCAPI is an example package to examplain how you can write a C function and call it from R.

You can do the same for a new {mypackage} or whatever R packge name you want.

## Example of add_one function for {mypackage}

When creating your {mypackage}, you can run this in a new mypackage folder with your desired title, description, language and your contact details.

```         
options(
    usethis.description = list(
        "Title" =  "R Internal C API Usage",
        "Description" = "RCAPI is an example package for R's internal C API usage.",
        "Authors@R" = utils::person(
            "My Name", "My Surname",
            email = "email@me.com",
            role = c("aut", "cre")
        ),
        Language =  "en"
    )
)
usethis::create_package(path = ".")
usethis::use_mit_license()
usethis::use_git()
usethis::use_github()
devtools::document()
usethis::use_package_doc()
usethis::use_c("mypackage")
```

Once you created the mypackage_add_one C function inside a src/mypackage.c file and call it from the add_one R function in R/add.R file, you can run:

```         
devtools::load_all()
pkgbuild::compile_dll(force = TRUE, register_routines = TRUE)
add_one(1)
```

If you want, you can look how I did this myself in [src/RCAPI.c](src/RCAPI.c) and [R/add.R](R/add.R) myself.

To document the package and check if it's is working well, run:

```         
devtools::check(document = TRUE)
```

Get all information about the example from [the original Davis Vaughan post](https://blog.davisvaughan.com/posts/2019-03-02-now-you-c-me/).

## Getting help with C-level R objects

Install pak::pak("henrikbengtsson/RNativeAPI") to get interactive help about R Native API.

At the C-level, all R objects are stored in a common datatype, the S-expression (SEXP) variant type, with subtypes (SEXPTYPE) for all R's data structures.

### [Vectors](https://github.com/hadley/r-internals/blob/master/vectors.md)

LGLSXP, INTSXP, REALSXP, CPLXSXP, STRSXP, VECSXP, RAWSXP, and EXPRSXP.

### [Strings](https://github.com/hadley/r-internals/blob/master/strings.md)

Character vectors are a more complex object made of vector CHARSXPs.

### [Environments](https://github.com/hadley/r-internals/blob/master/environments.md)

ENVSXP

### [Functions](https://github.com/hadley/r-internals/blob/master/functions.md)

CLOSXPs and the rarer BUILTINSXPs, SPECIALSXPs and FUNSXPs.

### [Symbols](https://github.com/hadley/r-internals/blob/master/symbols.md)

SYMSXPs

### [Pairlists](https://github.com/hadley/r-internals/blob/master/pairlists.md)

Including LISTSXPs and the related NILSXP, LANGSXP, and DOTSXP. This chapter also includes a discussion of attributes, which are powered by pair lists.

### [External pointers](https://github.com/hadley/r-internals/blob/master/external-pointers.md)

XPTRSXP

## References

* https://github.com/hadley/r-internals
* https://cran.r-project.org/doc/manuals/R-exts.html 
* https://cran.r-project.org/doc/manuals/r-release/R-ints.html 
* https://cran.stat.auckland.ac.nz/doc/manuals/r-devel/R-ints.html 
* http://adv-r.had.co.nz/C-interface.html 
* https://deepr.gagolewski.com/index.html 
* https://blog.davisvaughan.com/posts/2019-03-02-now-you-c-me/
Sphinx Documentation
---------------------

How to install Sphinx:
http://www.sphinx-doc.org/en/stable/usage/installation.html


Steps for documentation:

1. Document in .rst files.
    look in places like http://docutils.sourceforge.net/docs/user/rst/quickref.html
    for formatting help
2. If it is a new file, make sure to add to toctree in "index.rst"
3. Run "make html" in the "documentation" folder
4. Open "index.html" in documentation/_build/html/ to see the generated documentation.


Documentation structure:

Our main welcome page comes from "index.rst"
It contains the "table of contents tree" looking something like this

    .. toctree::
       :maxdepth: 2
       :caption: Contents:

       structure
       commands
       functions

This links multiple files together and display them in a hierarchy form.
To add more files, add them under toctree. In this case, add it below "functions".



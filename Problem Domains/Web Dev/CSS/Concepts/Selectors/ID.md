The CSS ID selector matches an element based on the value of the element's id attribute. In order for the element to be selected, its id attribute must match exactly the value given in the selector.
css

/* The element with id="demo" */
#demo {
  border: red 2px solid;
}

Syntax
css

#id_value { style properties }

Note that syntactically (but not specificity-wise), this is equivalent to the following attribute selector:
css

[id=id_value] { style properties }

The id_value value must be a valid CSS identifier. HTML id attributes which are not valid CSS identifiers must be escaped before they can be used in ID selectors.
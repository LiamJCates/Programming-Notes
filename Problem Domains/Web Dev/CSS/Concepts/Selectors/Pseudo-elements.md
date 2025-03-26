Pseudo-elements

A CSS pseudo-element is a keyword added to a selector that lets you style a specific part of the selected element(s).

Double colons (::) are used for pseudo-elements. This distinguishes pseudo-elements from pseudo-classes that use a single colon (:) in their notation. Note, browsers support single colon syntax for the original four pseudo-elements: ::before, ::after, ::first-line, and ::first-letter.

```css
selector::pseudo-element {
  property: value;
}
```

For example, ::first-line can be used to change the font of the first line of a paragraph.

```css
/* The first line of every <p> element. */
p::first-line {
  color: blue;
  text-transform: uppercase;
}
```

Pseudo-elements do not exist independently. The element of which a pseudo-element is a part is called its originating element. 

A pseudo-element must appear after all the other components in the complex or compound selector. The last element in the selector is the originating element of the pseudo-element. For example, you can select a paragraph's first line using p::first-line but not the first-line's children. So p::first-line > * is invalid.

A pseudo-element can be selected based on the current state of the originating element. For example, p:hover::first-line selects the first line (pseudo-element) of a paragraph when the paragraph itself is being hovered (pseudo-class).

Note: When a selector list contains an invalid selector, the entire style block is ignored.

### Typographic pseudo-elements

::first-line

    The first line-box of the originating element.
::first-letter

    The first letter, number, or symbol character on the first line of its originating element.
::cue

    The WebVTT cues within a selected element. This can be used to style captions and other cues in media with VTT tracks. The CSS pseudo-elements module also defines the ::postfix and ::prefix sub-pseudo elements. These are not yet supported by any browser.

### Highlight pseudo-elements

Selects document sections based on content and document status, enabling those areas to be styled differently to indicate that status to the user.

::selection

    The portion of a document that has been selected.
::target-text

    The document's target element. The target element is identified using the URL's fragment identifier.
::spelling-error

    A portion of text that the browser thinks is misspelled.
::grammar-error

    A portion of text that the browser thinks is grammatically incorrect.
::highlight()

    The elements in the highlight registry. It is used to create custom highlights.

### Tree-Abiding pseudo-elements

These pseudo-elements behave like regular elements, fitting seamlessly within the box model. They act as a child element that can be styled directly within the originating element hierarchy.

::before

    Creates a pseudo-element that is the first child of the selected element.
::after

    Creates a pseudo-element that is the last child of the selected element.
::marker

    The automatically generated marker box of a list item.
::placeholder

    The placeholder text in an input field.
::backdrop

    The backdrop of the originating element rendered in the top layer.

### Element-backed pseudo-elements

These pseudo-elements are real elements that are not otherwise selectable.

::details-content

    The expandable/collapsible contents of a <details> element.
::file-selector-button

    The button of an <input> of type="file".
::part()

    Any element within a shadow tree that has a matching part attribute.
::slotted()

    Any element placed into a slot inside an HTML template.

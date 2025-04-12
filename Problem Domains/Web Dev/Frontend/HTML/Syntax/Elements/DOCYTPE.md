# DOCTYPE

The first element in any standard HTML document is the DOCTYPE element.

```html
<!DOCTYPE html>
```

<!DOCTYPE html> is known as a document type declaration (DTD). 

It's not an HTML tag in the traditional sense; rather, it's an instruction to the web browser about what version of the HTML standard the document uses.

DTDs are strictly not an element that is part of the HTML standard, but it does tell the browser that this is an HTML document and tells it which version of HTML it is written in.

When HTML was young (1991-1992), doctypes were meant to act as links to a set of rules that the HTML page had to follow to be considered good HTML.

In the early days, different versions of HTML and various extensions were used, leading to inconsistencies in how browsers interpreted pages. The DOCTYPE declaration was introduced to help browsers render the page correctly according to the standards.

Doctypes used to look something like this:


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

More recently, the doctype is a historical artifact that needs to be included for everything else to work right. 



### Why it Matters

Standards Mode vs. Quirks Mode

Modern web browsers have two modes of rendering pages — Standards Mode and Quirks Mode. When <!DOCTYPE html> is included at the beginning of an HTML document, it tells the browser to render the page in Standards Mode, adhering to the latest HTML and CSS specifications.

Without <!DOCTYPE html>, browsers might render the page in Quirks Mode, leading to inconsistent and often unpredictable styles and layouts.
Compatibility

When using Quirks Mode, each web browser defines its own set of rules — often leading to inconsistencies between them. Using <!DOCTYPE html> ensures that your webpage is rendered in the same way in a wide range of browsers, from older versions to the most current ones.
Simplicity and Future-Proofing

The <!DOCTYPE html> declaration is short and simple, covering all versions of the HTML standard. This makes it future-proof and easy to remember.


HTML5: Simplifying the DOCTYPE

With the introduction of HTML5, the DOCTYPE declaration was significantly simplified. In previous versions of HTML (like HTML 4.01 and XHTML 1.0), the DOCTYPE declaration was longer and more complex, as it referred to a DTD that was specific to that version of HTML.

```html
HTML 4.01:
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

XHTML 1.1:
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
```

In HTML5, this was simplified to just <!DOCTYPE html>, reflecting the streamlined approach of HTML5 and its focus on being easy to write and understand.






Even though it is not part of the standard, it still follows the lack of case sensitivity

The <!DOCTYPE> declaration is NOT case sensitive.

Examples
```html
<!DOCTYPE html>
<!DocType html>
<!Doctype html>
<!doctype html>
```

# Valid HTML Elements in Different DOCTYPES

| Tag         | HTML 5 | HTML 4 | XHTML |
|------------|--------|--------|--------|
| `<a>`      | Yes    | Yes    | Yes    |
| `<abbr>`   | Yes    | Yes    | Yes    |
| `<acronym>`| No     | Yes    | Yes    |
| `<address>`| Yes    | Yes    | Yes    |
| `<applet>` | No     | Yes    | No     |
| `<area>`   | Yes    | Yes    | No     |
| `<article>`| Yes    | No     | No     |
| `<aside>`  | Yes    | No     | No     |
| `<audio>`  | Yes    | No     | No     |
| `<b>`      | Yes    | Yes    | Yes    |
| `<base>`   | Yes    | Yes    | Yes    |
| `<basefont>` | No  | Yes    | No     |
| `<bdi>`    | Yes    | No     | No     |
| `<bdo>`    | Yes    | Yes    | No     |
| `<big>`    | No     | Yes    | Yes    |
| `<blockquote>` | Yes | Yes   | Yes    |
| `<body>`   | Yes    | Yes    | Yes    |
| `<br>`     | Yes    | Yes    | Yes    |
| `<button>` | Yes    | Yes    | Yes    |
| `<canvas>` | Yes    | No     | No     |
| `<caption>`| Yes    | Yes    | Yes    |
| `<center>` | No     | Yes    | No     |
| `<cite>`   | Yes    | Yes    | Yes    |
| `<code>`   | Yes    | Yes    | Yes    |
| `<col>`    | Yes    | Yes    | No     |
| `<colgroup>`| Yes   | Yes    | No     |
| `<data>`   | Yes    | No     | No     |
| `<datalist>` | Yes  | No     | No     |
| `<dd>`     | Yes    | Yes    | Yes    |
| `<del>`    | Yes    | Yes    | No     |
| `<details>`| Yes    | No     | No     |
| `<dfn>`    | Yes    | Yes    | Yes    |
| `<dialog>` | Yes    | No     | No     |
| `<dir>`    | No     | Yes    | No     |
| `<div>`    | Yes    | Yes    | Yes    |
| `<dl>`     | Yes    | Yes    | Yes    |
| `<dt>`     | Yes    | Yes    | Yes    |
| `<em>`     | Yes    | Yes    | Yes    |
| `<embed>`  | Yes    | No     | No     |
| `<fieldset>` | Yes  | Yes    | Yes    |
| `<figcaption>` | Yes | No    | No     |
| `<figure>` | Yes    | No     | No     |
| `<font>`   | No     | Yes    | No     |
| `<footer>` | Yes    | No     | No     |
| `<form>`   | Yes    | Yes    | Yes    |
| `<frame>`  | No     | No     | No     |
| `<frameset>` | No   | Yes    | No     |
| `<h1>` to `<h6>` | Yes | Yes | Yes    |
| `<head>`   | Yes    | Yes    | Yes    |
| `<header>` | Yes    | No     | No     |
| `<hr>`     | Yes    | Yes    | Yes    |
| `<html>`   | Yes    | Yes    | Yes    |
| `<i>`      | Yes    | Yes    | Yes    |
| `<iframe>` | Yes    | Yes    | No     |
| `<img>`    | Yes    | Yes    | Yes    |
| `<input>`  | Yes    | Yes    | Yes    |
| `<ins>`    | Yes    | Yes    | No     |
| `<kbd>`    | Yes    | Yes    | Yes    |
| `<label>`  | Yes    | Yes    | Yes    |
| `<legend>` | Yes    | Yes    | Yes    |
| `<li>`     | Yes    | Yes    | Yes    |
| `<link>`   | Yes    | Yes    | Yes    |
| `<main>`   | Yes    | No     | No     |
| `<map>`    | Yes    | Yes    | No     |
| `<mark>`   | Yes    | No     | No     |
| `<meta>`   | Yes    | Yes    | Yes    |
| `<meter>`  | Yes    | No     | No     |
| `<nav>`    | Yes    | No     | No     |
| `<noframes>` | No   | Yes    | No     |
| `<noscript>` | Yes  | Yes    | Yes    |
| `<object>` | Yes    | Yes    | Yes    |
| `<ol>`     | Yes    | Yes    | Yes    |
| `<optgroup>` | Yes  | Yes    | Yes    |
| `<option>` | Yes    | Yes    | Yes    |
| `<output>` | Yes    | No     | No     |
| `<p>`      | Yes    | Yes    | Yes    |
| `<param>`  | Yes    | Yes    | Yes    |
| `<picture>` | Yes   | No     | No     |
| `<pre>`    | Yes    | Yes    | Yes    |
| `<progress>` | Yes  | No     | No     |
| `<q>`      | Yes    | Yes    | Yes    |
| `<rp>`     | Yes    | No     | No     |
| `<rt>`     | Yes    | No     | No     |
| `<ruby>`   | Yes    | No     | No     |
| `<s>`      | Yes    | Yes    | No     |
| `<samp>`   | Yes    | Yes    | Yes    |
| `<script>` | Yes    | Yes    | Yes    |
| `<section>` | Yes   | No     | No     |
| `<select>` | Yes    | Yes    | Yes    |
| `<small>`  | Yes    | Yes    | Yes    |
| `<source>` | Yes    | No     | No     |
| `<span>`   | Yes    | Yes    | Yes    |
| `<strike>` | No     | Yes    | No     |
| `<strong>` | Yes    | Yes    | Yes    |
| `<style>`  | Yes    | Yes    | Yes    |
| `<sub>`    | Yes    | Yes    | Yes    |
| `<summary>` | Yes   | No     | No     |
| `<sup>`    | Yes    | Yes    | Yes    |
| `<table>`  | Yes    | Yes    | Yes    |
| `<tbody>`  | Yes    | Yes    | No     |
| `<td>`     | Yes    | Yes    | Yes    |
| `<template>` | Yes  | No     | No     |
| `<textarea>` | Yes  | Yes    | Yes    |
| `<tfoot>`  | Yes    | Yes    | No     |
| `<th>`     | Yes    | Yes    | Yes    |
| `<thead>`  | Yes    | Yes    | No     |
| `<time>`   | Yes    | No     | No     |
| `<title>`  | Yes    | Yes    | Yes    |
| `<tr>`     | Yes    | Yes    | Yes    |
| `<track>`  | Yes    | No     | No     |
| `<tt>`     | No     | Yes    | Yes    |
| `<u>`      | Yes    | Yes    | No     |
| `<ul>`     | Yes    | Yes    | Yes    |
| `<var>`    | Yes    | Yes    | Yes    |
| `<video>`  | Yes    | No     | No     |
| `<wbr>`    | Yes    | No     | No     |
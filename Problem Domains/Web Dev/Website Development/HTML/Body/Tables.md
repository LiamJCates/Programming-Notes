Displaying Data with Tables


tables are for data. They're all about displaying data to the user. And historically, when HTML was created this was research data. It may have been specific data points in some experiments or other research. But today, we still use tables for displaying sets of data to users. As I said, we'll display some nutrition information, which is a nice natural fit for that. And there are other use cases for displaying that data. What tables are not for, and I'll touch on this in more detail later, is for formatting your pages or formatting your documents. So when we talk about displaying data, I truly mean data. If you're creating a table of contents for your document, that's not data, that's a table of contents. If you're going to display a lot of pictures and you want to do it in a grid, that's not data, that's pictures. And we'll use style sheets and some of the newer CSS or Cascading Style Sheet technologies to do that.

Defining HTML Tables

key components

caption        information for telling the user what this table shows them. And it's especially important for someone who's using, say, an assistive screen reader or other technology to help them understand the page

header        the top row in your table, or set of rows, that are going to provide information to the user that helps them understand the data that falls below each of those columns.

body         where the data will be displayed.

footer         can define things like aggregate values, sums, averages, etc.

Inside of the table, we're going to structure our data using rows and columns.

The rows are represented with a TR element, and that defines the wrapper around the entire row.

Inside of a row you could have a table header. So if this is the header of your table each element or cell within there is identified with a TH.

Within the body of your table, if you're inside a row and you're creating a cell, you use the TD or table data element to identify that table cell.

As you can see, when you create a table you take this row-first approach where you define the row and then you define each of the cells within that row that make up the columns.

Sometimes your data isn't going to fit neatly into grid spaces that are all aligned, and for that you have the ability to use colspan and rowspan attributes  so that a particular cell can span across multiple columns or multiple rows.
This allows you to handle things such as headers where you need to have a top- level header that spans a couple of different columns or when you've got data that applies to multiple levels of your grid.

Demo: Creating Tables

```html
<table>
	<caption></caption>
	<thead></thead>
	<tbody></tbody>
	<tfoot></tfoot>
<table>
```

We will expand each section below.

Now in the head, remember, we're going to start with a row-first approach. So we use a tr for a table row. But also in the head, for each element or each cell or column we use the th for the table head.

```html
<thead>
	<tr>
		<th>Header1</th>
		<th>Header2</th>
		<th>Header3</th>
	</tr>
</thead>
```

If I go down to the footer, I'm going to have the same number of columns. So I want to have another tr or row. In this case, I'll use the table data.
```html
<tfoot>
	<tr>
		<td>Footer1</td>
		<td>Footer2</td>
		<td>Footer3</td>
	</tr>
</tfoot>
```

now we get to the body of the table. So again, we use the tr for a row. And we're going to use those tds, or table datas.

```html
<tbody>
	<tr>
		<td>Row1 Col1</td>
		<td>Row1 Col2</td>
		<td>Row1 Col3</td>
	</tr>
	<tr>
		<td>Row2 Col1</td>
		<td>Row2 Col2</td>
		<td>Row2 Col3</td>
	</tr>
</tbody>
```

we've got a table, we've got a caption at the top with the information about what's in that table, and then we've got our table head. Now notice that, by convention, browsers are rendering those column headers as bolded text to make them stand out from the data. and, of course, the footer at the bottom providing some max values or aggregate values for us.



Formatting Tables

Typically we use style sheets.

```html
<style>
	table{
		margin-left: auto;
		margin-right: auto;
	}
	td, th{
		border-width: 1px;
		border-style: dashed;
		padding: 5px;
		margin: 5px;
	}
</style>
```
we'll type in a td, th, and then we'll use curly brackets. And what this does is indicates that when the browser sees the table data or table head element it should apply these styles to it.

Another common formatting task you might have is you may want to center that table in the middle of the page.

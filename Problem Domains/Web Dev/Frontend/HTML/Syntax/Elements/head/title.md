# Title

the <title> element is used to add a title to the document. This however can get confused with the h1 element, which is used to add a top level heading to your body content — this is also sometimes referred to as the page title. But they are different things!

    The h1 element appears on the page when loaded in the browser — generally this should be used once per page, to mark up the title of your page content (the story title, or news headline, or whatever is appropriate to your usage.)

    The <title> element is metadata that represents the title of the overall HTML document (not the document's content.)

The <title> element contents are also used in other ways. For example, if you try bookmarking the page (Bookmarks > Bookmark This Page or the star icon in the URL bar in Firefox), you will see the <title> contents filled in as the suggested bookmark name.




### **`<title>` Element**  

The `<title>` element is placed inside the `<head>` section of an HTML document and specifies the title of the web page. This title appears in the browser tab, bookmarks, and search engine results.

---

## **1. Basic Syntax**
```html
<title>Page Title Here</title>
```
The text inside `<title>` defines what appears in the browser tab.

---

## **2. Uses of the `<title>` Element**
### **1. Display Title in Browser Tab**
The `<title>` appears in the browser tab to help users identify open pages.
```html
<title>My Website - Home</title>
```
Example display in the browser tab:  
**My Website - Home** *(shown in the tab)*

---

### **2. Title in Search Engine Results (SEO)**
Search engines like Google display the `<title>` in search results.
```html
<title>Ultimate Guide to HTML Meta Tags | WebDev Hub</title>
```
Example in Google Search Results:
```
Ultimate Guide to HTML Meta Tags | WebDev Hub
www.example.com
Learn how to use HTML meta tags effectively to improve your SEO and web page performance.
```
A well-crafted title improves **SEO ranking** and **click-through rates (CTR).**

---

### **3. Bookmark & History Titles**
When a user bookmarks a page, the `<title>` appears as the default name.
```html
<title>HTML Basics - Learn Web Development</title>
```
Helps users recognize the saved webpage in their **bookmarks**.

---

### **4. Social Media Sharing Titles**
Social media platforms use the `<title>` as the **default share title** unless overridden by Open Graph (`og:title`) tags.
```html
<title>Best JavaScript Tips for Developers</title>
```
This improves **visibility** when sharing links.

---

## **3. Best Practices for Writing Effective `<title>` Tags**
| **Best Practice** | **Example** |
|------------------|------------|
| **Keep it Concise (50-60 characters)** | `<title>HTML Guide for Beginners</title>` |
| **Include Keywords (For SEO)** | `<title>Best Web Development Tips | Code Academy</title>` |
| **Be Descriptive & Engaging** | `<title>How to Build a Responsive Website - Step by Step</title>` |
| **Avoid Keyword Stuffing** | `<title>HTML, CSS, JavaScript, Web Development, SEO</title>` (too many keywords) |
| **Use Branding for Recognition** | `<title>WebDev Pro | Learn Coding Fast</title>` |

---

## **4. Full Example of an HTML Document with `<title>`**
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="Learn HTML title tag usage and best practices.">
    <meta name="keywords" content="HTML, title tag, SEO, web development">
    
    <title>How to Use the HTML Title Tag | WebDev Hub</title>

</head>
<body>
    <h1>Understanding the HTML `<title>` Tag</h1>
    <p>The title tag helps define the name of the web page in browsers and search engines.</p>
</body>
</html>
```
The title **"How to Use the HTML Title Tag | WebDev Hub"** will appear in:
- Browser tab
- Google search results
- Social media previews
- Bookmarks

---

## **5. Summary**
| **Feature** | **Usage** |
|------------|----------|
| **Defines the page title** | `<title>My Website - Home</title>` |
| **Appears in browser tabs** | Yes |
| **Used for SEO (Google, Bing, etc.)** | Yes |
| **Shown in browser history & bookmarks** | Yes |
| **Appears in shared social media links** | Yes |
| **Should be concise (50-60 characters)** | Yes |

Would you like more examples or SEO tips?
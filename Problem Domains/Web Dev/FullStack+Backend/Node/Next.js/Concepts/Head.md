The next/head component exports a custom Next.js- specific Head component.
We use it to set a page’s HTML title and meta elements, which are found
inside an HTML head component. To improve SEO ranking and enhance
usability, each page should have its own metadata. 

It is important to remember that the Head elements are not merged
across pages. Next.js’s client- side routing removes the content of the Head
element during the page transition.


```tsx
import type { NextPage } from "next";
import Head from "next/head";

const Hello: NextPage = () => {
    return (
        <div>
            <Head>
                <title>Hello World Page Title</title>
                <meta property="og:title" content="Hello World" key="title" />
            </Head>
            <div>Hello World!</div>
        </div>
    );
};

export default Hello;
```

We import the Head element from the next/head component and add it to
the returned JSX element, placing it above the existing content and wrap-
ping both in another div element because we need to return one element
instead of two.


https://nextjs.org/docs/app/building-your-application/routing/linking-and-navigating


### next/link Component

The next/link component exports a Link component. This component is
built on top of the React Link element. We use it instead of an HTML
anchor tag when we want to link to another page in the application,
enabling client- side transitions between pages. When clicked, the Link com-
ponent updates the browser DOM with the new DOM, scrolls to the top
of the new page, and adjusts the browser history. Furthermore, it provides
built-in performance optimizations, prefetching the linked page and its
data as soon as the Link component enters the viewport (the currently visible
part of the website). This background prefetch enables smooth page transi-
tions.

```jsx
import type { NextPage } from "next";
import Head from "next/head";
import Link from "next/link";

const Hello: NextPage = () => {
    return (
      <div>
      <Head>
        <title>Hello World Page Title</title>
        <meta property="og:title" content="Hello World" key="title" />
      </Head>
      <div>Hello World!</div>
      <div>
        Use the HTML anchor for an
        <a href="https://nostarch.com" > external link
        </a>
        and the Link component for an
        <Link href="/components/weather"> internal page
        </Link>
      </div>
      </div>
    );
};
export default Hello;
```
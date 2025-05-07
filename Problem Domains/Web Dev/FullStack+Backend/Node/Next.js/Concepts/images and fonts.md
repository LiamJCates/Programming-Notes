https://nextjs.org/docs/app/getting-started/images-and-fonts

https://nextjs.org/docs/app/building-your-application/optimizing/images
https://nextjs.org/docs/app/building-your-application/optimizing/fonts

https://nextjs.org/docs/api-reference/next/image

next/image Component
The next/image component exports an Image component used to display
images. This component is built on top of the native HTML <img> element.
It handles common layout requirements, such as filling all available space
and scaling images. The component can load modern image formats, such
as AVIF and WebP, and serve the image with the correct size for the cli-
ent’s screen. Furthermore, you have the option to use blurred placeholder
images and lazy-load the actual image as soon as it enters the viewport; this
enforces the visual stability of your website by preventing cumulative layout
shifts, which occur when an image renders after the page, causing the page
content to shift down. Cumulative layout shifts are considered a bad user
experience, and they can make the user lose their focus. 


```jsx
import type { NextPage } from "next";
import Head from "next/head";
import Link from "next/link";
import Image from "next/image";

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
        <a href="https://nostarch.com"> external link</a> 
      and the Link component for an
        <Link href="/components/weather"> internal page</Link>.
      <Image
        src="/vercel.svg"
        alt="Vercel Logo"
        width={72}
        height={16}
      />
    </div>
  </div>
  );
};

export default Hello;
```
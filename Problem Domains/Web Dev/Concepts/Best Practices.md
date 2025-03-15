### Web best practices

Best practices that web developers generally employ to ensure that their websites are usable by as many people as possible.

When doing web development, the main cause of uncertainty comes from the fact that you don't know what combination of technology each user will use to view your website:

    User 1 might be looking at it on an iPhone, with a small, narrow screen.
    User 2 might be looking at it on a Windows laptop with a widescreen monitor attached to it.
    User 3 might be visually impaired, and using a screen reader to read and interact with the web page.
    User 4 might be using a really old desktop machine that can't run modern browsers.

Because you don't know exactly what your users will use, you need to design defensively — make your website as flexible as possible, so that all of the above users can make use of it, even if they might not all get the same experience.

You'll come across the below concepts at some point in your studies, which represent best practices your websites should ideally adhere to. Don't worry about these too much for now. Throughout most of the course we try to teach these implicitly, meaning that when we teach you HTML, CSS, and JavaScript, our examples will follow the best practices where possible. Later on in your learning journey you will likely explore explicit teachings in these areas.

#### Progressive enhancement

    Creating a minimal experience that provides the essential functionality to all users, and layering on a better experience and other enhancements in browsers that can support them. Progressive enhancement is often seen as unimportant, because browsers tend to support new features more consistently these days, and people tend to have faster internet connections with higher limits on data usage. However, consider examples like cutting down on decoration to make a mobile experience smoother and save on data or providing a lighter, low-bandwidth experience for users who pay by the megabyte or have metered connections.

#### Cross-browser compatibility

    Trying to make sure your webpage works across as many devices as possible. This includes using technologies that all the browsers support, delivering better experiences to browsers that can handle them (progressive enhancement), and/or writing code so that it falls back to a simpler but still usable experience in older browsers (termed graceful degradation). It also requires testing to see if anything fails in certain browsers, and then more work to fix those failures.

#### Separating the layers

    Putting your content (HTML), styling (CSS), and behavior (JavaScript) in different code files, rather than lumping them all together in the same place. This is a good idea for many reasons, including code management and comprehension and teamwork/separation of roles. In reality, the separation is not always clear. It is an ideal to aim for where possible, rather than an absolute.

#### Responsive web design

    Making your functionality and layouts flexible so they can automatically adapt to different browsers. An obvious example is a website that is laid out one way in a widescreen browser on the desktop, but displays as a more compact, single-column layout on mobile phone browsers. Try adjusting the width of your browser window now, and see what happens to the site layout.

#### Performance

    Getting websites to load as quickly as possible, but also making them intuitive and easy to use so that users don't get frustrated and go somewhere else.

#### Internationalization

    Making websites usable by people from different cultures, who speak different languages to your own. There are technical considerations here (such as altering your layout so that it still works OK for right-to-left or top-to-bottom languages), and human ones (such as using simple, non-slang language so that diverse cultures are more likely to understand your text).

#### Privacy & Security

    These two concepts are related but different. Privacy refers to allowing people to go about their business privately and not spying on them or collecting more of their data than you absolutely need to. Security refers to constructing your website in a secure way so that malicious users cannot steal information contained on it from you or your users.

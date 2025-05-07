# Pre-rendering and Publishing

While you can start building full- stack Next.js applications with the
information you’ve learned so far, you’ll find it useful to know one more
advanced topic: the dif ferent ways to render and publish your application
and their implications for its performance.
Next.js provides three options for pre-rendering your app with its built-
in server. The first, static site generation (SSG), generates the HTML at build
time. Thus, each request will always return the same HTML, which remains
static and is never re- created. The second option, server-side rendering (SSR),
generates new HTML files on each request, and the third, incremental static
regeneration (ISR), combines both approaches.
Next.js lets us choose our pre-rendering option on a per-page basis,
meaning the full- stack application can contain pages with SSG, SSR, and
ISR, as well as client- side rendering for some React components. You can
also create a complete static export of your site by running next export. The
exported application will run independently on all infrastructures, as it
doesn’t need the built-in Next.js server.
To gain experience with these rendering approaches, we’ll create a new
page that displays the data from our names API for each rendering option.

The.Complete.Developer page 83...
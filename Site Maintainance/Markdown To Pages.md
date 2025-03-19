Easy Markdown to Github Pages

https://nicolas-van.github.io/easy-markdown-to-github-pages/

Introduction

How to turn any Github repository with a bunch of Markdown files into a simple website using Github Pages and Jekyll.

    You don’t need to use the command line or anything other than your browser.
    It doesn’t require any knowledge in Jekyll.
    It’s completely compatible with any bunch of markdown files you already have in any existing repository without any modification to those files. That includes the basic README.md almost all repositories contain.
    The markdown files will remain just as readable and usable in Github than in your website.

In fact this guide uses the same configuration and can be read both in Github and in Github Pages, at your preference:

    Here is the link to the Github version
    Here is the link to the Github Pages version


Determine the repository where you want to activate Github Pages

Create this **_config.yml** file in the root repository.

```yml
remote_theme: pages-themes/hacker@v0.2.0
plugins:
  - jekyll-relative-links
  - jekyll-remote-theme
relative_links:
  enabled: true
  collections: true
include:
  - CONTRIBUTING.md
  - README.md
  - LICENSE.md
  - COPYING.md
  - CODE_OF_CONDUCT.md
  - CONTRIBUTING.md
  - ISSUE_TEMPLATE.md
  - PULL_REQUEST_TEMPLATE.md
```

It’s basically just a few tuning of Github Pages’ default configuration to have a better handling of Markdown files.

### Activate Github Pages in your repository configuration

On the Github page of your project go into Settings > Options > Github Pages

In the Source option, select master branch then Save

You must also choose a theme
https://pages.github.com/themes/

replace the **remote_theme** value in the first line of the config file with your selected them 

That’s it! Now you can just use the link provided by Github to access your website:

Usage guide

    Any markdown file in your repository will display in your Github Pages website. You just have to use the same path to access it and replace the .md extension by .html.
    To make links between your Markdown files just use a relative path to the other Markdown file. The configuration you copy pasted in your _config.yml provides a plugin to convert those URLs. So your Markdown files will have correct links both in Github and Github Pages.
    The index page of your website can be a index.md file or a README.md file. If both exists the index.md file has priority.
    You should be able to use any Github Flavored Markdown.

Known differences between Github and Github Pages

    No automatic links with Github Pages. The Github Markdown renderer can automatically detect a simple copy-pasted link and make it a clickable link. Github Pages doesn’t propose a feature to reproduce that behavior, so you’ll have to braces your links with the []() syntax.





### CSS in HTML emails

Email is an essential piece of any marketing strategy.

However, email campaigns don’t come without their pain points.

Low open rates, poor conversions, and formatting issues can spell doom for even the best-planned email campaigns.

Fortunately, those first two problems may be solved with simply copy changes. But the formatting issues are a different issue if they are caused by your CSS code.

This article will explain how CSS is used, as well as break down some of the problems often associated with implementing CSS in HMTL emails and provide a few possible solutions.

CSS can be far less reliable with emails.

### Why CSS in HTML emails can cause problems

When you build an email in most of the popular email tools on the market today, you’ll see your finished product as it was intended. It may include Flash elements, tables, or compelling graphics.

However, when that content is opened by readers using their various email providers, they may see something totally different.

The main reason behind these display issues in CSS emails isn’t the code. Rather, it’s the capabilities of the email provider, all of which can differ depending on the version of the email provider you are using.

So, for instance, specific code may call for an image-heavy template. While it might look great on your friend’s Gmail app, you could open the email in Outlook on your desktop and it would appear stripped down with no images:
 

Another common problem with CSS emails relates to formatting. Carefully planned boxes or templates may not stack up correctly or appear condensed instead of taking up the whole screen as they should.



Adding to the problem is that different providers will be able to display different features. This means some of your contacts will be able to see the email just fine, while others might get a stripped or poorly formatted version of it.

And of course, those poorly formatted emails may have a major impact on the success of your email campaigns. Especially when you consider that the majority of emails that are displayed improperly are deleted in less than three seconds.
How to be successful with CSS in HTML emails

Just because there can be issues with CSS in HTML emails doesn’t mean you should abandon efforts to use it. It all comes down to determining which codes are absolutely needed and how to style them so they can be rendered by email platforms.

Campaign Monitor has a fairly detailed and helpful list of the most popular CSS commands and which email providers do and do not support each piece of code.

https://www.campaignmonitor.com/css/

Here are a few options to consider that can keep your email displays impressive without running into CSS issues:

1. Use inline CSS.

If you are set on using CSS, your best bet is to use inline code. This is the most effective and widely used method for including CSS in HTML emails. According to Litmus research, 86% of email designers inline their CSS.

The benefit of using inline CSS is that most email providers will support this style, which means you’re likely to get the best results without running into any formatting trouble. However, since your email developer will have to write extra code in each line for each additional design element beyond basic HTML, it can take extra time to create email templates.

https://lh4.googleusercontent.com/8zUGQcIUGz2RDzcsCh0FKDM7_qbvC88Dz1fNCyJ6Mbs0-zUzs6dErrwnGUA7b2LnLnhT4UAv8vyak94C0x9hXqlBwKuWUji7f8g8ZjWTA2wTt5Bn8Cn8eXkMLyD39uNlOGkJazxt

Source: Litmus

There are email template builder tools that can help streamline this development, but that same Litmus research found that nearly 70% of marketers were inlining their CSS by hand, or without any inline builders.
2. Avoid embedded and external CSS in HTML emails.

There are two other CSS options that can be considered in your HTML emails, but these increase the risk of display problems.

    Embedded CSS: This style is becoming more popular with the rise of mobile and responsive emails. Embedded CSS codes are determined in one place of an email, generally in the <head> section as a <style>. Some email servers still strip the information out of this section, which can cause display problems.

    External CSS: This style is used heavily for website development and generally should not be used for emails. With external CSS, developers link to a stylesheet somewhere else on the server. However, these links are mostly blocked by email providers.

It’s best to avoid these two methods if possible.
3. Stay away from background images.

Although it looks nice, an email formatted with a background image does not display anything other than alt text  if it can’t be rendered by the email program.

The result is just a blank screen with broken image icons and a few words of text.

And what’s more, a growing number of email readers are even voluntarily turning off images in their emails to reduce load time and improve email speed. Google recently revealed that 43% of Gmail users actually don’t read emails with background images on.

So, if four out of every 10 people aren’t looking at your background image designs anyway, you can reduce the chances of your images failing to load due to CSS issues for the other six by simply leaving these images out of your emails altogether.
4. See which platforms your audience is using.

Although it’s definitely not a best practice, there are some marketers out there who may not have the time or resources to develop a CSS-friendly email template that works across the board. So, as a result, they might just try to optimize their email so it works for most of their audience.

Apple Mail remains the most popular email service. Roughly 40% of people use it to read their emails. That’s followed by Gmail at around 20%. But that doesn’t mean your contacts are using the same platforms.

For instance, if you are a B2B company that sells data center services, the majority of your customers may read their emails in Outlook on their work desktop. But if you’re a B2C company that sells clothing, you’re probably seeing more customers opening emails on mobile in Gmail.

If you know your audience, you can format your emails so they work in the most popular platforms, and sacrifice the quality that the minority of your audience will see.

It should be repeated that although this is an option, it’s definitely not recommended.
5. Don’t use CSS at all.

If you’re unsure or cautious about sending HTML emails with CSS, there is a simple solution: plain-text emails.

Most of the big email providers (including Gmail and Outlook) already allow users to see a plain-text version of your email if you are using CSS code that is not recognized. But you could take it one step further and just send all of your emails using basic HTML or plain text.

While they do not look flashy and definitely won’t win any design awards, this might be the best way to get your message across. Take a look at this example from Nintendo:

 

https://lh3.googleusercontent.com/AEd790PX2q32vQ3L70I38arsBwBZJy54sJu1QJMa1_IDyvPmgJ7eEDDSJwL8dM7gmHmtojatlrlzQCpYkR0IWDKZ-szWMmALlVevkakn_nZ8UaScSUkshsO5EpvcTagGmZwZSoZ5

 

Source: Shopify

While this example is a transactional email, this style also works well for welcome, reengagement, and nurturing emails. Plain-text versions tend to have a more personalized feel.

Here’s another example from the Atlanta Falcons:

https://lh4.googleusercontent.com/Zt3gwPaEtbtPsW9_aZSQcUfHPhWrUfD3T1nyaDgqen9cYU2LTlf6yEx0NleXALE0Z68Y-I62O6uI94M_uVxuYWs9asUO1GLhvsabb_BOG7eamgzqb2npx2SMLvezgMSkyvCTPwZf

Source: Atlanta Falcons

This email does another great job of supplying necessary information without using heavy design elements. By using plain-text, the Atlanta Falcons sales team ensures that all users are able to open and see the email, creating a positive customer experience.
Wrap up

So, should you be using CSS in HTML emails?

Like everything else in the marketing world, it depends.

If you must use CSS, your safest bet is to use inline code. It may take more time in the long run, but you have a better chance of your email being viewed as it was intended. But, if you’re unsure about how your design will render, make sure you include a plain-text view option – or simply send your entire email in plain text.

Remember, it’s better to be safe than sorry.
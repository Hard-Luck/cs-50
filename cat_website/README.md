# CS50 Final project:

======================

### A site that users can sign up for and get a random fact emailed to them every day.

I will build this site using flask for the back end along with SQLite3 for user details and preferences. I will collect emails using forms and use Gmail API to automate the sending of emails along with the random cat fact API for the request of facts to send.

1. Gmail API; https://developers.google.com/gmail/api
2. Cat fact API; https://fungenerators.com/api/facts/?ref=apilist.fun

The front end will be primarily HTML and CSS (with Bootstrap) however, I do intend to implement JavaScript where appropriate and I will need to get more familiar with the language and its functionality.

Things I intend to research during this project:

1. APIs
2. Email sending regulations
3. Password management and storage on databases
4. Database security
5. Version Control - Git and GutHub, .gitignore
6. CSS Standardisation
7. Software design and file management
8. @required decorators (Flask, maybe more genrally Python)

##### Website design

Create a standalone authorization finctionality that could be used in any website, and implement using flask's Blueprint module.

Home page (not logged in) will have registration link and log in functionality

Home page (logged in) will have links to "interests selection" with check boxes and a submit, which will save interests to a database. Also links to a "settings" page where user can update info and a "Try it out" page.

settings page (login required) will have options to update email address, subscribe/unsubscribe to emails and change password.

Try it out page - will allow users to enter an interest with a form and see they type of randomly generated fact they would recieve if subscibed to the email.

All pages will extend the main layout page.

##### Functionality

Emails sent are going to be via googles Gmail API and set up to execute on a timer -- Not sure exactly how to do this but idea should work.

    -At first glance, apscheduler.schedulers.background import BackgroundScheduler seems like a good fit.

Passwords will be hashed before being stored in the database - session_id will be updated -- Need to figure this out, have a good idea but not exact.

1 interest will be randomly selected each day and random fact API will be queried and fact inserted into email template -- This I think I can do! :)

### Plan

================

- Flesh out the bases and have the functionality somewhat working ie. all pages loading and queries functioning
- Get the apis working
- Make the pages look much better using more advanced html and CSS
- consider adding JavaScript to places, arguably less for functionality more for practice and education

### Changes

The random facts API wasn't free so I opted to use a free API which only generated cat facts, I felt this was a fitting choice for CS50.

## Final Message:

================

I'm not very good at asthetic design work though I have tried. I am very proud of the functionality of the site, having not really used APIs
(except for in cs50 briefy). I have learned a bunch of things along the way not only in this project but also on the course. I would reccomened this to anybody. Thanks to David and the team!

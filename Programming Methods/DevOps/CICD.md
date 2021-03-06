https://www.infoworld.com/article/3271126/what-is-cicd-continuous-integration-and-continuous-delivery-explained.html

Continuous integration (CI) and continuous delivery (CD) embody a culture, set of operating principles, and collection of practices that enable application development teams to deliver code changes more frequently and reliably, known as the CI/CD pipeline.

CI/CD is one of the best practices for devops teams to implement. It is also an agile methodology best practice, as it enables software development teams to focus on meeting business requirements, code quality, and security because deployment steps are automated.
CI/CD defined

Continuous integration is a coding philosophy and set of practices that drive development teams to implement small changes and check in code to version control repositories frequently. Because most modern applications require developing code in different platforms and tools, the team needs a mechanism to integrate and validate its changes.

[ Also on InfoWorld: Get started with CI/CD: Automating your application delivery with CI/CD pipelines ]

The technical goal of CI is to establish a consistent and automated way to build, package, and test applications. With consistency in the integration process in place, teams are more likely to commit code changes more frequently, which leads to better collaboration and software quality.

Continuous delivery picks up where continuous integration ends. CD automates the delivery of applications to selected infrastructure environments. Most teams work with multiple environments other than the production, such as development and testing environments, and CD ensures there is an automated way to push code changes to them.

CI/CD tools help store the environment-specific parameters that must be packaged with each delivery. CI/CD automation then performs any necessary service calls to web servers, databases, and other services that may need to be restarted or follow other procedures when applications are deployed.

Continuous integration and continuous delivery require continuous testing because the objective is to deliver quality applications and code to users. Continuous testing is often implemented as a set of automated regression, performance, and other tests that are executed in the CI/CD pipeline.

[ Learn Java from beginning concepts to advanced design patterns in this comprehensive 12-part course! ]

A mature CI/CD devops practice has the option of implementing continuous deployment where application changes run through the CI/CD pipeline and passing builds are deployed directly to production environments. Teams practicing continuous delivery elect to deploy to production on a daily or even hourly schedule, though continuous delivery isn’t always optimal for every business application.  
Related video: How to deliver code faster with CI/CD
How continuous integration improves collaboration and quality

Continuous integration is a development philosophy backed by process mechanics and some automation. When practicing CI, developers commit their code into the version control repository frequently and most teams have a minimal standard of committing code at least daily. The rationale behind this is that it’s easier to identify defects and other software quality issues on smaller code differentials rather than larger ones developed over extensive period of times. In addition, when developers work on shorter commit cycles, it is less likely for multiple developers to be editing the same code and requiring a merge when committing.

Teams implementing continuous integration often start with version control configuration and practice definitions. Even though checking in code is done frequently, features and fixes are implemented on both short and longer time frames. Development teams practicing continuous integration use different techniques to control what features and code are ready for production.
[ Also on InfoWorld: 3 ways to kick off a devops program ]

Many teams use feature flags, a configuration mechanism to turn features and code on or off at run time. Features that are still under development are wrapped with feature flags in the code, deployed with the master branch to production, and turned off until they are ready to be used. According to a recent survey, 63 percent of teams that use feature flags report better testing and higher quality software. Feature flagging tools such as CloudBees Rollout, Optimizely Rollouts, and LaunchDarkly integrate with CI/CD tools and enable feature-level configurations.

Another technique for managing features is version control branching. A branching strategy such as Gitflow is selected to define protocols over how new code is merged into standard branches for development, testing and production. Additional feature branches are created for ones that will take longer development cycles. When the feature is complete, the developers can then merge the changes from feature branches into the primary development branch. This approach works well, but it can become difficult to manage if there are many features being developed concurrently.

The build process itself is then automated by packaging all the software, database, and other components. For example, if you were developing a Java application, CI would package all the static web server files such as HTML, CSS, and JavaScript along with the Java application and any database scripts.

CI not only packages all the software and database components, but the automation will also execute unit tests and other testing. This testing provides feedback to developers that their code changes didn’t break any existing unit tests.

Most CI/CD tools let developers kick off builds on demand, triggered by code commits in the version control repository, or on a defined schedule. Teams need to discuss the build schedule that works best for the size of the team, the number of daily commits expected, and other application considerations. A best practice to ensure that commits and builds are fast, otherwise, it may impede the progress of teams trying to code fast and commit frequently.
Continuous testing goes beyond test automation

Automated testing frameworks help quality assurance engineers define, execute, and automate various types of tests that can help development teams know whether a software build passes or fails. They include functionality tests that are developed at the end of every sprint and aggregated into a regression test for the entire application. These regression tests then inform the team whether a code change failed one or more of the tests developed across all functional areas of the application where there is test coverage.

A best practice is to enable and require developers to run all or a subset of regressions tests in their local environments. This step ensures that developers only commit code to version control after regression tests pass on the code changes.
[ Also on InfoWorld: What is agile methodology? Modern software development explained ]

Regression tests are just the start. Performance testing, API testing, static code analysis, security testing, and other testing forms can also be automated. The key is to be able to trigger these tests either through command line, webhook, or web service and that they respond with success or fail status codes.

Once testing is automated, continuous testing implies that the automation is integrated into the CI/CD pipeline. Some unit and functionality tests can be integrated into CI that flags issues before or during the integration process. Tests that require a full delivery environment such as performance and security testing are often integrated into CD and performed after builds are delivered to target environments.
The CD pipeline automates changes to multiple environments

Continuous delivery is the automation that pushes applications to delivery environments. Most development teams typically have one or more development and testing environments where application changes are staged for testing and review. A CI/CD tool such as Jenkins, CircleCI, AWS CodeBuild, Azure DevOps, Atlassian Bamboo, or Travis CI is used to automate the steps and provide reporting.

A typical CD pipeline has build, test, and deploy stages. More sophisticated pipelines include many of these steps:

    Pulling code from version control and executing a build.
    Executing any required infrastructure steps that are automated as code to stand up or tear down cloud infrastructure.
    Moving code to the target computing environment.
    Managing the environment variables and configuring them for the target environment.
    Pushing application components to their appropriate services, such as web servers, API services, and database services.
    Executing any steps required to restarts services or call service endpoints that are needed for new code pushes.
    Executing continuous tests and rollback environments if tests fail.
    Providing log data and alerts on the state of the delivery.

As an example, Jenkins users define their pipelines in a Jenkinsfile that describes different stages such as build, test, and deploy. Environment variables, options, secret keys, certifications, and other parameters are declared in the file and then referenced in stages. The post section handles error conditions and notifications.  

More sophisticated CD may have other steps such as performing data synchronizations, archiving information resources, or performing application and library patching. CI/CD tools typically support a marketplace of plug-ins. For example, Jenkins lists more than 1,500 plug-ins that support integration with third-party platforms, user interface, administration, source code management, and build management.
[ Also on InfoWorld: What is Jenkins? The CI server explained ]

Once a CI/CD tool is selected, development teams must make sure that all environment variables are configured outside the application. CI/CD tools allow setting these variables, masking variables such as passwords and account keys, and configuring them at time of deployment for the target environment.

CD tools also provide dashboard and reporting functions. If builds or deliveries fail, they alert developers with information on the failures. They integrate with version control and agile tools, so they can be used to look up what code changes and user stories made up a build.
Implementing CI/CD pipelines with Kubernetes and serverless architectures

Many teams operating CI/CD pipelines in cloud environments also use containers such as Docker and orchestration systems such as Kubernetes. Containers allow for packaging and shipping applications in standard, portable ways. Containers make it easy to scale up or tear down environments that have variable workloads.

There are many approaches to using containers, infrastructure as code, and CI/CD pipelines together. You can explore the options by working through tutorials such as Kubernetes with Jenkins or Kubernetes with Azure DevOps.

Serverless computing architectures present another avenue for deploying and scaling applications. In a serverless environment, the infrastructure is fully managed by the cloud service provider and the application consumes resources as needed based on its configuration. On AWS for example, serverless applications run as Lambda functions and deployments can be integrated into a Jenkins CI/CD pipeline with a plug-in.
CI/CD enables more frequent code deployments

To recap, CI packages and tests software builds and alerts developers if their changes failed any unit tests. CD is the automation that delivers changes to infrastructure and executes additional tests.

CI/CD pipelines are designed for businesses that want to improve applications frequently and require a reliable delivery process. The added effort to standardize builds, develop tests, and automate deployments is the manufacturing process for deploying code changes. Once in place, it enables teams to focus on the process of enhancing applications and less on the system details of delivering it to computing environments.
[ Keep up with the latest developments in software development, cloud computing, data analytics, and machine learning with the InfoWorld Daily newsletter ]

CI/CD is a devops best practice because it addresses the misalignment between developers who want to push changes frequently, with operations that want stable applications. With automation in place, developers can push changes more frequently. Operations teams see greater stability because environments have standard configurations, there is continuous testing in the delivery process, environment variables are separated from the application, and rollback procedures are automated.

The impact of implementing CI/CD pipelines can be measured as a devops key performance indicator (KPI). KPI’s such as deployment frequency, change lead time, and mean time to recovery (MTTR) from an incident are often improved when CI/CD with continuous testing is implemented. However, CI/CD is just one process that can drive these improvements, and there are other prerequisites to improving deployment frequencies.

Getting started with CI/CD requires development teams and operational teams to collaborate on technologies, practices, and priorities. Teams need to develop consensus on the right approaches for their business and technologies so that once CI/CD is in place the team is onboard with following practices consistently.

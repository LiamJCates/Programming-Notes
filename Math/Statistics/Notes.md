Probability and Statistics for Programmers

Probability 
the study of random events. 

Statistics 
the discipline of using data samples to support claims about populations.


Most statistical analysis is based on probability, which is why these pieces are usually presented together.




Beware anecdotal evidence

typically based on data that is unpublished and usually personal. 

Small number of observations or data points
    low confidence in estimation of the true standard deviation

Selection bias
    Definition: Selection bias refers to a flaw in the sampling process where certain individuals or groups are more likely to be included in a study or analysis than others, which can distort the results.
    Example: In a study about the effectiveness of a medication, if only people who are already using the medication (and not people who have refused or dropped out) are included, the sample is biased, and the results may not accurately reflect the broader population's response.

Confirmation Bias

    Definition: Confirmation bias occurs when individuals favor information that confirms their preexisting beliefs or hypotheses while disregarding or undervaluing evidence that contradicts them.
    Example: If someone believes that a particular diet is effective for weight loss, they may seek out articles, testimonials, or studies that support this belief while ignoring evidence that suggests otherwise.

Inaccuracy: 
    Anecdotes are often personal stories, and often misremembered, misrepresented, repeated inaccurately, etc.




A statistical approach

Data collection


Descriptive statistics: 

Generate statistics that summarize the data concisely, and evaluate different ways to visualize data.


Exploratory data analysis: We will look for patterns, differences, and other
features that address the questions we are interested in. At the same
time we will check for inconsistencies and identify limitations.

Hypothesis testing: Where we see apparent effects, like a difference be-
tween two groups, we will evaluate whether the effect is real, or
whether it might have happened by chance.

Estimation: We will use data from a sample to estimate characteristics of
the general population.


By performing these steps with care to avoid pitfalls, we can reach conclu-
sions that are more justifiable and more likely to be correct.





Data Collection


The goal of the survey is to draw conclusions about a population

participants in a survey are called respondents; 
respondent: A person who responds to a survey.
a group of respondents is called a cohort. 

sample: The subset of a population used to collect data.

representative: A sample is representative if every member of the popula-
tion has the same chance of being in the sample.

oversampling: The technique of increasing the representation of a sub-
population in order to avoid errors due to small sample sizes.


cross-sectional study 
captures a snapshot of a group at a point in time. 

longitudinal study
observes a group repeatedly over a period of time.


when observations are conducted several times; each deployment is called a cycle.
for a study to be longitudinal, the same cohort must be sampled in each cycle


In general, cross-sectional studies are meant
to be representative, which means that every member of the target popu-
lation has an equal chance of participating. Of course that ideal is hard to
achieve in practice.



A study may not be representative; instead it is deliberately oversampled.
Particular groups may be selected at rates higher than their representation in the
total population. The reason for oversampling is to make sure that the num-
ber of respondents in each of these groups is large enough to draw valid
statistical inferences.



Significance
In the previous exercise, you compared the gestation period for first babies
and others; if things worked out, you found that first babies are born about
13 hours later, on average.
A difference like that is called an apparent effect; that is, there might be
something going on, but we are not yet sure. There are several questions
we still want to ask:
• If the two groups have different means, what about other summary
statistics, like median and variance? Can we be more precise about
how the groups differ?
• Is it possible that the difference we saw could occur by chance, even
if the groups we compared were actually the same? If so, we would
conclude that the effect was not statistically significant.
• Is it possible that the apparent effect is due to selection bias or some
other error in the experimental setup? If so, then we might conclude
that the effect is an artifact; that is, something we created (by accident)
rather than found.



record: In a database, a collection of information about a single person or
other object of study.
field: In a database, one of the named variables that makes up a record.
table: In a database, a collection of records.
raw data: Values collected and recorded with little or no checking, calcula-
tion or interpretation.
recode: A value that is generated by calculation and other logic applied to
raw data.

summary statistic: The result of a computation that reduces a dataset to a
single number (or at least a smaller set of numbers) that captures some
characteristic of the data. examples include mean, variance, and median

apparent effect: A measurement or summary statistic that suggests that
something interesting is happening.

statistically significant: An apparent effect is statistically significant if it is
unlikely to occur by chance.

artifact: An apparent effect that is caused by bias, measurement error, or
some other kind of error.





Descriptive Statistics


Mean

If you have a sample of n values, xi, the mean, µ, is the sum of the values divided by the number of values; in other words

µ = (1/n) ∑ixi

The words “mean” and “average” are sometimes used interchangeably, but
I will maintain this distinction:

• The “mean” of a sample is the summary statistic computed with the
previous formula.

• An “average” is one of many summary statistics you might choose to
describe the typical value or the central tendency of a sample.



Sometimes the mean is a good description of a set of values. 

For example, apples are all pretty much the same size (at least the ones sold in supermarkets). So if I buy 6 apples and the total weight is 3 pounds, it would be a reasonable summary to say they are about a half pound each.

But pumpkins are more diverse. 

Suppose I grow several varieties in my garden, and one day I harvest three decorative pumpkins that are 1 pound each, two pie pumpkins that are 3 pounds each, and one Atlantic Giant® pumpkin that weighs 591 pounds. 

The mean of this sample is 100 pounds, 

but if I told you “The average pumpkin in my garden is 100 pounds,” that would be wrong, or at least misleading.

In this example, there is no meaningful average because there is no typical
pumpkin.

central tendency: 
A characteristic of a sample or population; 
intuitively, it is the most average value.



### Variance



Variance
If there is no single number that summarizes pumpkin weights, we can do
a little better with two numbers: mean and variance.

In the same way that the mean is intended to describe the central tendency,
variance is intended to describe the spread. 

The variance of a set of values

σ2 = (1/n) ∑(x − µ)2

The term x-µ is called the “deviation from the mean” 
variance is the mean squared deviation, which is why it is denoted σ2. 

The square root of variance, σ, is called the standard deviation.
By itself, variance is hard to interpret. 

One problem is that the units are strange; in this case the measurements are in pounds, so the variance is in
pounds squared. 

Standard deviation is more meaningful in this case, the units are pounds.


If you have prior experience, you might have seen a formula for variance with n − 1 in the denominator, rather than n.
This statistic is called the “sample variance,” and it is used to estimate the variance in a population using a sample. 


spread: 
A characteristic of a sample or population; 
intuitively, it describes how much variability there is.

variance:
A summary statistic often used to quantify spread.

standard deviation: 
The square root of variance, 
also used as a measure of spread.


### Distributions


Summary statistics are concise, but dangerous, because they obscure the data. 

An alternative is to look at the distribution of the data, which describes how often each value appears.

The most common representation of a distribution is a histogram,
a graph that shows the frequency or probability of each value.


To get from frequencies to probabilities, we divide by n, which is called normalization

The normalized histogram is called a PMF, which stands for “probability
mass function”; that is, it’s a function that maps from values to probabilities

frequency: 
The number of times a value appears in a sample.

probability: 
A frequency expressed as a fraction of the sample size.

histogram: 
A mapping from values to frequencies, or a graph that shows this mapping.

normalization: The process of dividing a frequency by a sample size to get
a probability.

distribution: A summary of the values that appear in a sample and the
frequency, or probability, of each.

PMF: Probability mass function: a representation of a distribution as a
function that maps from values to probabilities.








As part of survival analysis, it is often useful to compute the remaining life-
time of, for example, a mechanical component. If we know the distribution
of lifetimes and the age of the component, we can compute the distribution
of remaining lifetimes.


A Pmf of lifetimes is used along with the age of the part concerned to produce a new Pmf using only the distribution of remaining
lifetimes.


If you are given a PMF, you can compute the mean by summing the products of each value and it's probability
similarly we can compute the variance by summing the products of each value's probability and the value minus the mean squared


### Outliers

mode: The most frequent value in a sample.

outlier: A value far from the central tendency.
Some of these might just be unusual cases, but many of them are
probably due to errors, either in the reporting or recording of data
It is always a good idea to check for
outliers, and sometimes it is useful and appropriate to discard them

trim: To remove outliers from a dataset.



### Other visualizations

Histograms and PMFs are useful for exploratory data analysis; once you
have an idea what is going on, it is often useful to design a visualization
that focuses on the apparent effect.


say the biggest differences in the distributions are near the mode, it then makes sense to zoom in on that part of the graph, and to transform the data to emphasize differences.

bin: A range used to group nearby values.

relative risk: A ratio of two probabilities, often used to measure a difference between distributions.


One way to summarize data is with relative risk, which is a ratio
of two probabilities. For example, the probability that a first baby is born
early is 18.2%. For other babies it is 16.8%, so the relative risk is 1.08. That
means that first babies are about 8% more likely to be early.

Imagine that someone you know is pregnant, and it is the beginning of
Week 39. What is the chance that the baby will be born in the next week?
How much does the answer change if it’s a first baby?
We can answer these questions by computing a conditional probability,
which is (ahem!) a probability that depends on a condition. In this case, the
condition is that we know the baby didn’t arrive during Weeks 0–38.

conditional probability: A probability computed under the assumption that some condition holds.

clinically significant: A result, like a difference between groups, that is relevant in practice.

At this point we have explored the data and seen several apparent effects.
For now, let’s assume that these effects are real (but let’s remember that it’s
an assumption). How should we report these results?
The answer might depend on who is asking the question. For example, a
scientist might be interested in any (real) effect, no matter how small. A
doctor might only care about effects that are clinically significant; that is,
differences that affect treatment decisions. A pregnant woman might be
interested in results that are relevant to her, like the conditional probabilities
in the previous section.
How you report results also depends on your goals. If you are trying to
demonstrate the significance of an effect, you might choose summary statis-
tics, like relative risk, that emphasize differences. If you are trying to reas-
sure a patient, you might choose statistics that put the differences in context.
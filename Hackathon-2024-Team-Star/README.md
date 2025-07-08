# Introduction
The 2024 Hackathon at CSU was hosted by the USDA and tasked teams with developing a machine learning model that could identify meat grades based on the training photos we were provided.

Our team was not very experienced, as I was the only one with any ML experience (and that was only half a semester of Intro to ML). We were, however, awarded an honorable mention for the amount of growth we showed over 48 hours, since half of our two-person team had extremely limited programming knowledge but did manage to produce a working model that was nearly able to complete the task.

Below is the outline of our approach. Ours was the only team to preprocess the images by converting them into greyscale.

# Hackathon-2024-Team-Star

1) Find main area of the image
     - Greyscale / coloration

2) Divide into quadrants
   
3) Average fat content for each quadrant
   - Weight vector?
     
4) Average all quadrants (what % avg = what score)

Pseudocode for getting training data:

````
Vars to keep a running count of each steak type so we can average at the end
totalSelect = 0
totalPrime = 0
...
Vars to store final avg for each type of steak
avgSelect% = 0
avgPrime% = 0
...


for i in len(training photos): 
     -convert current image to black and white for simplicity
     -identify the main part of the streak from the background / outer fat
     -divide the main part into quadrants or more sections
     totalFat = 0
     finalFat = 0
     for j in len(quadrants):
          -calculate fat by % of white vs black pixels
          totalFat += fat% calculated
     finalFat = totalFat / len(quadrants)    # Find final fat % of the current steak by averaging all sections
     - find what steak type this was from the spreadsheet and add its avg to running average per steak type.

     
````

Libraries:

1) OpenCV: image processing, grayscaling, analysis

2) Image aggregation (analysis of multiple segments): NumPy, Pandas, XGBoost (boosted tree modeling)
...

using System.Collections.Generic;
using UnityEngine;
using System.IO;
 
public class TimeTracker : MonoBehaviour {
 
    public static List <float> CheckpointTimes= new List <float>();
    public static float TimeCnt;
    private int i;

    void Start(){
        TimeCnt = 0;
        i = 0;
    }
 
 
    void Update() {
        TimeCnt += Time.deltaTime;
    }
    public void ReachedCheckpoint(){
       if(i==0){
           CheckpointTimes.Add(Time.unscaledTime);
       }
       else{
           CheckpointTimes.Add(Time.unscaledTime - CheckpointTimes[i-1]);
       }
       i++;
    }
 //referenced https://support.unity.com/hc/en-us/articles/115000341143-How-do-I-read-and-write-data-from-a-text-file-
    public void ExportTimeData(){
      string path = "Assets/CheckpointTimes.txt";

      StreamWriter writer = new StreamWriter(path, true);
      foreach (long t in CheckpointTimes){
        //Write some text to the test.txt file
        
        writer.WriteLine("\nTime: ",t);
        
      }
     writer.Close();
        //Re-import the file to update the reference in the editor
     //AssetDatabase.ImportAsset(path); 
     //TextAsset asset = (TextAsset)Resources.Load("CheckpointTimes");
        //Print the text from the file
     //Debug.Log(asset.text);
    }
}

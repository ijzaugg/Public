using System.Collections;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;
using TMPro;

public class Survey3 : MonoBehaviour
{
    [SerializeField] Slider difficulty;
    public string entry1;
    [SerializeField] Slider improvement;
    public string entry2;
    [SerializeField] Slider device;
    public string entry3;

    string URL = "https://docs.google.com/forms/u/0/d/e/1FAIpQLSfh_uBEBv45JID6mWiIn7jsWSnIAYN_KJHgEblAl5Ne5k3EPA/formResponse";

    public void Send()
    {
        StartCoroutine(Post3(difficulty.value.ToString(), improvement.value.ToString(), device.value.ToString()));
    }

    IEnumerator Post3(string s1, string s2, string s3)
    {
        WWWForm form = new WWWForm();
        form.AddField(entry1, s1);
        form.AddField(entry2, s2);
        form.AddField(entry3, s3);

        using (UnityWebRequest www = UnityWebRequest.Post(URL, form))
        {
            yield return www.SendWebRequest();
        }

    }

}
using System.Collections;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;
using TMPro;

public class Survey : MonoBehaviour
{
    [SerializeField] Slider answer1;
    [SerializeField] TMP_InputField answer2;

    string URL = "https://docs.google.com/forms/u/0/d/e/1FAIpQLSfzTXUyyGzx9hvXHlugDZbZ1ToEqRjPC8uP2f5JhlwlqdYW7Q/formResponse";


    public void Send()
    {
        StartCoroutine(Post(answer1.value.ToString(), answer2.text));
    }

    IEnumerator Post(string s1, string s2)
    {
        WWWForm form = new WWWForm();
        form.AddField("entry.1374361237", s1);
        form.AddField("entry.747969361", s2);

        using (UnityWebRequest www = UnityWebRequest.Post(URL, form))
        {
            yield return www.SendWebRequest();
        }

    }

}
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.Networking;

public class SurveyClass : MonoBehaviour
{
    [SerializeField] InputField outputResult;
    public GameObject questionGroup;
    public QAClass qaResult;
    string URL = "https://docs.google.com/forms/u/0/d/e/1FAIpQLSfzTXUyyGzx9hvXHlugDZbZ1ToEqRjPC8uP2f5JhlwlqdYW7Q/formResponse";

    // Start is called before the first frame update
    void Start()
    {
        qaResult = new QAClass();
    }

    // Update is called once per frame
    void Update()
    {

    }

    public void SubmitAnswer()
    {
        qaResult = ReadQuestionAndAnswer(questionGroup);
    }

    QAClass ReadQuestionAndAnswer(GameObject questionGroup)
    {
        QAClass result = new QAClass();

        GameObject q = questionGroup.transform.Find("Question").gameObject;

        GameObject a = GameObject.Find("Answer").gameObject;
        Slider answer = a.transform.GetChild(0).GetComponent<Slider>();

        result.Question = q.GetComponent<TMP_Text>().text;
        result.Answer = answer.value;

        StartCoroutine(Post(result.Answer.ToString()));
        return result;
    }

   /* public void Send()
    {
        StartCoroutine(Post());
    }*/

    IEnumerator Post (string s)
    {
        WWWForm form = new WWWForm();
        form.AddField("entry.1374361237", s);

        using (UnityWebRequest www = UnityWebRequest.Post(URL, form))
        {
            yield return www.SendWebRequest();
        }
    }
}

[System.Serializable]
public class QAClass
{
    public string Question = "";
    public float Answer = 5;
}
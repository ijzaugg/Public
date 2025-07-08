using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;
using TMPro;

public class Survey2 : MonoBehaviour
{
    [SerializeField] Toggle fps;
    public string entry1;
    [SerializeField] Toggle action;
    public string entry2;
    [SerializeField] Toggle puzzle;
    public string entry3;
    [SerializeField] Toggle racing;
    public string entry4;
    [SerializeField] Toggle horror;
    public string entry5;
    [SerializeField] Toggle rpg;
    public string entry6;
    [SerializeField] Toggle arcade;
    public string entry7;
    [SerializeField] Toggle sports;
    public string entry8;
    [SerializeField] Toggle card;
    public string entry9;
    [SerializeField] Toggle mmo;
    public string entry10;
    [SerializeField] Toggle strategy;
    public string entry11;
    [SerializeField] Toggle trivia;
    public string entry12;
    [SerializeField] Toggle sandbox;
    public string entry13;
    [SerializeField] Toggle fighting;
    public string entry14;
    [SerializeField] TMP_InputField other;
    public string entry15;
    [SerializeField] Slider confidence;
    public string entry16;

    string URL = "https://docs.google.com/forms/u/0/d/e/1FAIpQLSfh_uBEBv45JID6mWiIn7jsWSnIAYN_KJHgEblAl5Ne5k3EPA/formResponse";

    public void Send()
    {
        StartCoroutine(Post2(fps.isOn.ToString(), action.isOn.ToString(), puzzle.isOn.ToString(), racing.isOn.ToString(),
            horror.isOn.ToString(), rpg.isOn.ToString(), arcade.isOn.ToString(), sports.isOn.ToString(), card.isOn.ToString(),
            mmo.isOn.ToString(), strategy.isOn.ToString(), trivia.isOn.ToString(), sandbox.isOn.ToString(), fighting.isOn.ToString(),
            other.text, confidence.value.ToString()));
    }

    IEnumerator Post2(string s1, string s2, string s3, string s4, string s5, string s6, string s7, string s8, string s9, string s10,
        string s11, string s12, string s13, string s14, string s15, string s16)
    {
        WWWForm form = new WWWForm();
        form.AddField(entry1, s1);
        form.AddField(entry2, s2);
        form.AddField(entry3, s3);
        form.AddField(entry4, s4);
        form.AddField(entry5, s5);
        form.AddField(entry6, s6);
        form.AddField(entry7, s7);
        form.AddField(entry8, s8);
        form.AddField(entry9, s9);
        form.AddField(entry10, s10);
        form.AddField(entry11, s11);
        form.AddField(entry12, s12);
        form.AddField(entry13, s13);
        form.AddField(entry14, s14);
        form.AddField(entry15, s15);
        form.AddField(entry16, s16);


        using (UnityWebRequest www = UnityWebRequest.Post(URL, form))
        {
            yield return www.SendWebRequest();
        }

    }

}

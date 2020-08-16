import speech_recognition as sr
from gtts import gTTS

r = sr.Recognizer()
mic = sr.Microphone()

with mic as source:
    print("Speak now:")
    audio = r.listen(mic)

try:
    print("You said: " + r.recognize_google(audio))

except sr.UnknownValueError:
    print("[ERROR]Audio not understandable. Please try again")

except sr.RequestError as e:
    print("[ERROR]Cannot obtain results, {0}".format(e)) 


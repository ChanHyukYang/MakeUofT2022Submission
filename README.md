# MakeUofT2022Submission
# Inspiration
WIth masks now becoming a semi-permanent accessory to the face, our ability to comprehend others’ emotions and, as a result, engage in meaningful interpersonal communication has been severely restricted. This has, however, led to an inadvertent simulation of facial paralysis, helping to destigmatize such conditions. Coupled with the fact that dementia patients often communicate best via non-verbal means, we believe a mask that can combine fashion with emotional displays can help express oneself while masked and therefore improve interpersonal communications, along with helping to destigmatize facial paralysis and ensure effective communication with dementia patients. In such a pursuit, however, we aim to maintain the main purpose of a mask and have implemented means to keep airborne pollutants out. In short, we strive to implement style, empathy and effectiveness through our electronic mask.

# What it does
eFace is an electronic face mask that aims to display various facial expressions with a press of a button. There’s no need for familiarity with circuitry, as one only needs to cycle through various precoded expressions via a convenient button attached to the mask itself, with the whole mask being powered by attached 9v batteries. Included with the eFace are fans which act to keep airborne pollutants out, ensuring the integrity of any face mask’s purpose. The LED lights on the fan perimeters also act to enhance the personalities available on display, coupled with the LED display for the mouth to result in a device effective in non-verbal displays of emotion.

# How we built it
The eFace was crafted from cardboard, with covers for key electrical components modeled using Fusion 360 from scratch. This ensured speed of prototyping while also making sure electrical components were not exposed for safety reasons.

For electronics we soldered two 9V batteries to a 5V buck converter, attaching its output to our arduino nano and switch to power our LEDs while also being able to alternate between various preset patterns for expressions.

For software, we took existing dictionaries available for our LEDs and searched for preset patterns and cycles. We then back-engineered this code and mapped onto an LED matrix in order to create custom patterns, allowing us to express various emotions onto the mask.

# Challenges we ran into
A major difficulty we ran into regarding the physical design of the device was the scale of our initial proposal. We intended to include a see-through eye-cover with accompanying LED lights to further lend expressivity to our product. However, time constraints led to us pivoting into just the face cover, with plans and CAD designs for the eye-mask serving as potential next steps for our product. The wiring of the various components on the mask itself also proved a challenge, as soldering the various components to the specified mask dimensions required numerous iterations of writing. On the software end, locating the library for the led displays and then changing preset design patterns to the custom expressions we wanted was a challenge, with further research on display matrices used to solve this problem.

# Accomplishments that we're proud of
We are most proud of our ability to pivot from our initial, more ambitious design which also contained a see-through eye cover mesh with its own accompanying LEDs to a more manageable mask that still delivers on our initial goal of increasing expressibility via face masks. Being able to reverse engineer our custom LED patterns from existing libraries and patterns was also a challenge we are proud to have met.

# What we learned
Delegation of tasks according to expertise while providing effective aid when needed greatly expedited our progress, and along with research skills garnered from locating libraries and example code for our LEDs were key learning takeaways. Also, the uses of tiny IoT devices and Fusion 360 were made evident by their ability to deliver on our goals, which going forward should prove invaluable in prototyping.

# What's next for eFace
To further improve the expressivity, usability, and reliability of eFace, the following improvements are recommended:

Utilize rechargeable batteries to ensure long-term usability
Implement sensors inside the mask to allow the option of displaying current facial expressions automatically on the led display
Implement a see-through eye-cover with accompanying LED displays to further expand upon available facial expressions

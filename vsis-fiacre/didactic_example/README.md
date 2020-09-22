# Didactic Example

This folder contains the source code for the didactic example used in the article.

### Dependency

You need to install the following tools to reproduce the model checking experiments and to generate the executable VSIS:

1. Tina toolbox (http://projects.laas.fr/tina//);
2. Fiacre (http://projects.laas.fr/fiacre/)
3. Hippo (TODO). To avoid compatibility problems with the 'frac' name, rename the 'frac' binary from the hippo lib to 'frac2hippo';
4. Gpp preprocessor (https://logological.org/gpp);
5. building package for C language (such as gcc) to compile the models.

## Moldel

The Fiacre model presented in this folder holds the behavior specified by the Cause and Effect Matrix illustrated in Figure 1. For more information, see section 5 of the respective article.

![MCE](../../imgs/mce_example.png)

Figure 1. Cause and Effect Matrix (Safety Specification).

## Model Checking

The 'model_checking' folder holds the source code to perform the formal verification of the VSIS. The fiacre model is extended with the LTL properties and inputs variables to emulate the environment. To execute the Model checking Toolchain, call the commands below:

1. List the available options:

```
cd model_checking
./verify
# No arguments supplied.
# Please, select a valid argument: effect1, effect2, effect3 or effect4.
```

2. Select one of the options available:

```
./script effect1
```

For each one of the available options, the script will apply the appropriate abstraction and perform the formal verification of the model. See the model's source code in the 'models' folder for more information. The fiacre models are self-explanatory.

## VSIS Executable

The folder 'vsis' holds the source code to generate an executable version of the fiacre model. Execute the 'generate' script to create the executable from the fiacre model using hippo. Remind that the didatic example is provided without a PLC companion.

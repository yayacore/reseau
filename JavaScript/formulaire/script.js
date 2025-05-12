console.log("test");

const form = document.querySelector("form");    //récup les attributs de l'elmnt HTML "form"

form.addEventListener("submit", onLogin);    //écoute sur le submit (le bouton)

function onLogin(event) {
    event.preventDefault(); //désactive le comportement par default de l'évenement grâce à la fonction preventDefault() pr la vérification des champs du formulaire
    const formData = new FormData(event.target);

    /**
     * ici ça print ds la console les données que l'utilisateur 
     * a saisi dans les champs du formulaire
     */
    const nom = formData.get("nom");
    const prenom = formData.get("prenom");
    const email = formData.get("mail");
    const message = formData.get("message");

    console.log(formData);
    console.log(formData.get("nom"));
    console.log(formData.get("prenom"));
    console.log(formData.get("email"));
    console.log(formData.get("message"));

    /**
     * conditions pr que les champs soient valides
     */

    if (nom.length < 2 || nom.length > 20) {
        console.log("erreur lors de la saisie du nom");
        //return false;
        document.getElementById("nomErreur").textContent = "le nom doit contenir entre 2 et 20 caractères";
    }

    if (prenom.length < 2 || prenom.length > 20) {
        console.log("erreur lors de la saisie du prénom");
        //return false;
        document.getElementById("prenomErreur").textContent = "le prenom doit contenir entre 2 et 20 caractères";
    }

    if (message.length > 100 || message.length < 10) {
        console.log("erreur lors de la saisie de votre message");
        //return false;
    }

    if (emailVerify) {
        document.getElementById("emailErreur").textContent = "l'adresse mail saisie n'est pas valide";
    }

    function emailVerify(email) {

        const emailFormat = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/; // Création d'un objet RegexExp (vérifier qu'une adresse mail est valide)

        if (emailFormat.test(email)) {
            return true;
        } else {
            return false
        }
    }
}

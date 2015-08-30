
(cl:in-package :asdf)

(defsystem "collab-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Intention" :depends-on ("_package_Intention"))
    (:file "_package_Intention" :depends-on ("_package"))
    (:file "SceneComposition" :depends-on ("_package_SceneComposition"))
    (:file "_package_SceneComposition" :depends-on ("_package"))
    (:file "ObjectProperties" :depends-on ("_package_ObjectProperties"))
    (:file "_package_ObjectProperties" :depends-on ("_package"))
  ))